#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <sys/sysinfo.h>

#define LOGF "debugmon.log"
#define PROC "/proc"

uid_t cari_uid(const char *user) {
    struct passwd *p = getpwnam(user);
    if (!p) {
        fprintf(stderr, "Ga nemu user %s\n", user);
        exit(1);
    }
    return p->pw_uid;
}

int angka_doang(const char *s) {
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

void tulis_log_fail(const char *nama) {
    FILE *f = fopen(LOGF, "a");
    if (!f) return;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char waktu[64];
    strftime(waktu, sizeof(waktu), "[%d:%m:%Y]-[%H:%M:%S]", tm);
    fprintf(f, "%s_%s_FAILED\n", waktu, nama);
    fclose(f);
}

void tulis_log_ok(const char *nama) {
    FILE *f = fopen(LOGF, "a");
    if (!f) return;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char waktu[64];
    strftime(waktu, sizeof(waktu), "[%d:%m:%Y]-[%H:%M:%S]", tm);
    fprintf(f, "%s_%s_RUNNING\n", waktu, nama);
    fclose(f);
}

void jd_daemon() {
    pid_t p = fork();
    if (p < 0) exit(1);
    if (p > 0) exit(0);
    setsid();
    umask(0);
    chdir("/home/ywwzz/Sisop-2-2025-IT36/soal_4");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    open("/dev/null", O_RDONLY);
    open("/dev/null", O_WRONLY);
    open("/dev/null", O_RDWR);
}

void pantau(const char *user, int mode) {
    uid_t uid = cari_uid(user);

    while (1) {
        DIR *d = opendir(PROC);
        if (!d) {
            sleep(5);
            continue;
        }

        struct dirent *e;
        while ((e = readdir(d))) {
            if (!angka_doang(e->d_name)) continue;

            int pid = atoi(e->d_name);
            char path[256], line[256], nama[256] = "-";
            FILE *f;
            uid_t uidp;

            snprintf(path, sizeof(path), PROC"/%d/status", pid);
            f = fopen(path, "r");
            if (!f) continue;

            while (fgets(line, sizeof(line), f)) {
                if (sscanf(line, "Uid: %d", &uidp) == 1) break;
            }
            fclose(f);

            if (uidp != uid) continue;

            snprintf(path, sizeof(path), PROC"/%d/comm", pid);
            f = fopen(path, "r");
            if (f) {
                fgets(nama, sizeof(nama), f);
                nama[strcspn(nama, "\n")] = 0;
                fclose(f);
            }

            if (strcmp(nama, "debugmon") == 0) {
                tulis_log_ok(nama);
            } else if (mode) {
                if (kill(pid, SIGKILL) == 0) {
                    tulis_log_fail(nama);
                }
            }
        }

        closedir(d);
        sleep(5);
    }
}

void stop_mon(const char *user) {
    DIR *d = opendir(PROC);
    if (!d) return;

    struct dirent *e;
    uid_t uid = cari_uid(user);

    while ((e = readdir(d))) {
        if (!angka_doang(e->d_name)) continue;

        int pid = atoi(e->d_name);
        char path[256], line[1024], exepath[256], real[256];
        uid_t uidp;

        snprintf(path, sizeof(path), PROC"/%d/status", pid);
        FILE *f = fopen(path, "r");
        if (!f) continue;

        while (fgets(line, sizeof(line), f)) {
            if (sscanf(line, "Uid: %d", &uidp) == 1) break;
        }
        fclose(f);
        if (uidp != uid) continue;

        snprintf(exepath, sizeof(exepath), PROC"/%d/exe", pid);
        ssize_t len = readlink(exepath, real, sizeof(real) - 1);
        if (len == -1) continue;
        real[len] = '\0';

        if (!strstr(real, "debugmon")) continue;

        if (kill(pid, SIGTERM) == 0) {
            printf("Stop debugmon (PID %d) user %s\n", pid, user);
        } else {
            perror("gagal stop");
        }
    }

    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc == 3 && strcmp(argv[1], "list") == 0) {
        uid_t uid = cari_uid(argv[2]);
        DIR *d = opendir(PROC);
        if (!d) return 1;

        struct sysinfo s_info;
        sysinfo(&s_info);
        double uptime = s_info.uptime;
        long ticks_per_sec = sysconf(_SC_CLK_TCK);

        struct dirent *e;
        while ((e = readdir(d))) {
            if (!angka_doang(e->d_name)) continue;

            int pid = atoi(e->d_name);
            char path[256], line[256], nama[256] = "-";
            FILE *f;
            uid_t uidp;
            double mem = 0, cpu = 0;

            snprintf(path, sizeof(path), PROC"/%d/status", pid);
            f = fopen(path, "r");
            if (!f) continue;

            while (fgets(line, sizeof(line), f)) {
                if (sscanf(line, "Uid: %d", &uidp) == 1) {
                    if (uidp != uid) {
                        fclose(f);
                        goto next;
                    }
                }
            }
            fclose(f);

            snprintf(path, sizeof(path), PROC"/%d/comm", pid);
            f = fopen(path, "r");
            if (f) {
                fgets(nama, sizeof(nama), f);
                nama[strcspn(nama, "\n")] = 0;
                fclose(f);
            }

            snprintf(path, sizeof(path), PROC"/%d/stat", pid);
            f = fopen(path, "r");
            if (f) {
                long unsigned utime, stime, cutime, cstime, starttime;
                fscanf(f, "%*d %*s %*c %*d %*d %*d %*d %*d "
                        "%*u %*u %*u %*u %*u "
                        "%lu %lu %lu %lu %*d %*d %*d %*d %*d %*d "
                        "%*u %*u %*d %*d %*u %lu",
                        &utime, &stime, &cutime, &cstime, &starttime);
                fclose(f);

                long total_time = utime + stime + cutime + cstime;
                double seconds = uptime - (starttime / (double)ticks_per_sec);
                if (seconds > 0)
                    cpu = 100.0 * ((total_time / (double)ticks_per_sec) / seconds);
            }

            snprintf(path, sizeof(path), PROC"/%d/statm", pid);
            f = fopen(path, "r");
            if (f) {
                long pages;
                if (fscanf(f, "%ld", &pages) == 1) {
                    long psize = sysconf(_SC_PAGE_SIZE) / 1024;
                    mem = pages * psize;
                }
                fclose(f);
            }

            printf("PID: %d CMD: %s MEM: %.2f KB CPU: %.2f%%\n", pid, nama, mem, cpu);
        next: ;
        }

        closedir(d);
    } else if (argc == 3 && strcmp(argv[1], "daemon") == 0) {
        jd_daemon();
        pantau(argv[2], 0);
    } else if (argc == 3 && strcmp(argv[1], "fail") == 0) {
        jd_daemon();
        pantau(argv[2], 1);
    } else if (argc == 3 && strcmp(argv[1], "stop") == 0 || strcmp(argv[1], "revert") == 0) {
        stop_mon(argv[2]);
    } else {
        printf("Pake:\n");
        printf("  %s list <user>\n", argv[0]);
        printf("  %s daemon <user>\n", argv[0]);
        printf("  %s fail <user>\n", argv[0]);
        printf("  %s stop <user>\n", argv[0]);
        printf("  %s revert <user>\n", argv[0]);
        return 1;
    }

    return 0;
}
//
