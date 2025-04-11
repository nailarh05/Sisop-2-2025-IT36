#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>

void download_and_extract();
void filter_files();
void combine_files();
void decode_file();
void show_usage(char *program_name);
int is_directory_exists(const char *path);
int is_file_exists(const char *path);
void execute_command(char *argv[]);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        download_and_extract();
        return 0;
    } else if (argc == 3 && strcmp(argv[1], "-m") == 0) {
        if (strcmp(argv[2], "Filter") == 0) {
            filter_files();
        } else if (strcmp(argv[2], "Combine") == 0) {
            combine_files();
        } else if (strcmp(argv[2], "Decode") == 0) {
            decode_file();
        } else {
            show_usage(argv[0]);
        }
    } else {
        show_usage(argv[0]);
    }
    
    return 0;
}

void download_and_extract() {
    if (is_directory_exists("Clues")) {
        printf("Clues directory already exists. Skipping download.\n");
        return;
    }
    
    printf("Downloading Clues.zip...\n");
    
    char *wget_args[] = {
        "wget", 
        "https://drive.usercontent.google.com/u/0/uc?id=1xFn1OBJUuSdnApDseEczKhtNzyGekauK&export=download", 
        "-O", 
        "Clues.zip", 
        NULL
    };
    execute_command(wget_args);
    
    printf("Extracting Clues.zip...\n");
    
    char *unzip_args[] = {"unzip", "Clues.zip", NULL};
    execute_command(unzip_args);
    
    printf("Removing Clues.zip...\n");
    
    char *rm_args[] = {"rm", "Clues.zip", NULL};
    execute_command(rm_args);
    
    printf("Download and extraction completed.\n");
}

int is_directory_exists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISDIR(st.st_mode));
}

int is_file_exists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISREG(st.st_mode));
}

void execute_command(char *argv[]) {
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Command failed with status %d\n", WEXITSTATUS(status));
        }
    }
}

void filter_files() {
    DIR *dir;
    struct dirent *entry;
    char filepath[512];
    char dest_filepath[512];
    
    if (!is_directory_exists("Clues")) {
        printf("Clues directory does not exist. Run without arguments first.\n");
        return;
    }
    
    if (!is_directory_exists("Filtered")) {
        mkdir("Filtered", 0755);
    }
    
    const char *clue_dirs[] = {
        "Clues/ClueA", 
        "Clues/ClueB", 
        "Clues/ClueC", 
        "Clues/ClueD"
    };
    
    for (int i = 0; i < 4; i++) {
        dir = opendir(clue_dirs[i]);
        if (dir == NULL) {
            perror("opendir");
            continue;
        }
        
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            char *ext = strrchr(entry->d_name, '.');
            if (ext && strcmp(ext, ".txt") == 0) {
                if ((strlen(entry->d_name) == 5) && (entry->d_name[1] == '.')) {
                    char first_char = entry->d_name[0];
                    
                    if (isalpha(first_char) || isdigit(first_char)) {
                        snprintf(filepath, sizeof(filepath), "%s/%s", clue_dirs[i], entry->d_name);
                        snprintf(dest_filepath, sizeof(dest_filepath), "Filtered/%s", entry->d_name);
                        
                        char *cp_args[] = {"cp", filepath, dest_filepath, NULL};
                        execute_command(cp_args);
                    }
                }
                
            }
        }
        
        closedir(dir);
    }
    
    printf("Filtering completed.\n");
}

void combine_files() {
    DIR *dir;
    struct dirent *entry;
    char filepath[512];
    FILE *source, *dest;
    char letter_files[26][16];
    char digit_files[10][16];
    int letter_count = 0;
    int digit_count = 0;
    char buffer[256];
    
    if (!is_directory_exists("Filtered")) {
        printf("Filtered directory does not exist. Run filter mode first.\n");
        return;
    }
    
    dir = opendir("Filtered");
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        if (strlen(entry->d_name) == 5 && entry->d_name[1] == '.') {
            if (isdigit(entry->d_name[0])) {
                strcpy(digit_files[digit_count], entry->d_name);
                digit_count++;
            } else if (isalpha(entry->d_name[0])) {
                strcpy(letter_files[letter_count], entry->d_name);
                letter_count++;
            }
        }
    }
    
    closedir(dir);
    
    for (int i = 0; i < letter_count - 1; i++) {
        for (int j = 0; j < letter_count - i - 1; j++) {
            if (strcmp(letter_files[j], letter_files[j + 1]) > 0) {
                char temp[16];
                strcpy(temp, letter_files[j]);
                strcpy(letter_files[j], letter_files[j + 1]);
                strcpy(letter_files[j + 1], temp);
            }
        }
    }
    
    for (int i = 0; i < digit_count - 1; i++) {
        for (int j = 0; j < digit_count - i - 1; j++) {
            if (strcmp(digit_files[j], digit_files[j + 1]) > 0) {
                char temp[16];
                strcpy(temp, digit_files[j]);
                strcpy(digit_files[j], digit_files[j + 1]);
                strcpy(digit_files[j + 1], temp);
            }
        }
    }
    
    dest = fopen("Combined.txt", "w");
    if (dest == NULL) {
        perror("fopen");
        return;
    }
    
    int max_count = (digit_count > letter_count) ? digit_count : letter_count;
    
    for (int i = 0; i < max_count; i++) {
        if (i < digit_count) {
            snprintf(filepath, sizeof(filepath), "Filtered/%s", digit_files[i]);
            source = fopen(filepath, "r");
            if (source) {
                while (fgets(buffer, sizeof(buffer), source) != NULL) {
                    fputs(buffer, dest);
                }
                fclose(source);
            }
        }
        
        if (i < letter_count) {
            snprintf(filepath, sizeof(filepath), "Filtered/%s", letter_files[i]);
            source = fopen(filepath, "r");
            if (source) {
                while (fgets(buffer, sizeof(buffer), source) != NULL) {
                    fputs(buffer, dest);
                }
                fclose(source);
            }
        }
    }
    
    dir = opendir("Filtered");
    if (dir != NULL) {
        rewinddir(dir);
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            if (strlen(entry->d_name) != 5 || entry->d_name[1] != '.') {
                char *ext = strrchr(entry->d_name, '.');
                if (ext && strcmp(ext, ".txt") == 0) {
                    snprintf(filepath, sizeof(filepath), "Filtered/%s", entry->d_name);
                    source = fopen(filepath, "r");
                    if (source) {
                        while (fgets(buffer, sizeof(buffer), source) != NULL) {
                            fputs(buffer, dest);
                        }
                        fclose(source);
                    }
                }
            }
        }
	        closedir(dir);
    }
    
    fclose(dest);
    printf("Files combined successfully.\n");
}

void decode_file() {
    FILE *source, *dest;
    int ch;
    
    if (!is_file_exists("Combined.txt")) {
       printf("Combined.txt does not exist. Run combine mode first.\n");
        return;
    }
    
    source = fopen("Combined.txt", "r");
    if (source == NULL) {
        perror("fopen");
        return;
    }
    
    dest = fopen("Decoded.txt", "w");
    if (dest == NULL) {
        perror("fopen");
        fclose(source);
        return;
    }
    
    while ((ch = fgetc(source)) != EOF) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = ((ch - 'a' + 13) % 26) + 'a';
            } else {
                ch = ((ch - 'A' + 13) % 26) + 'A';
            }
        }
        fputc(ch, dest);
    }
    
    fclose(source);
    fclose(dest);
    
    printf("Decoding completed. Result saved to Decoded.txt\n");
    
}

void show_usage(char *program_name) {
    printf("Usage:\n");
    printf("  %s                  : Download and extract Clues.zip\n", program_name);
    printf("  %s -m Filter        : Filter files with single letter or digit names\n", program_name);
    printf("  %s -m Combine       : Combine filtered files in alternating order\n", program_name);
    printf("  %s -m Decode        : Decode the combined content using ROT13\n", program_name);
}
