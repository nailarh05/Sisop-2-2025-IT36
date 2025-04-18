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



### Soal 2**
a. mendowload, unzip sebuah file acak dan menghapus file zip asli setelah melakukan unzip.
b. mendeycrp
 
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
else if (argc == 3 && strcmp(argv[1], "daemon") == 0) {
    jd_daemon();
    pantau(argv[2], 0);
}

```
![Screenshot 2025-04-17 134334](https://github.com/user-attachments/assets/65006d84-5b8e-4b65-a6cf-49be34af06ff)
![Screenshot 2025-04-17 134635](https://github.com/user-attachments/assets/3805743f-f9be-4319-8b2b-b45f6c98d583)


c. debugmon stop seharusnya dia akan menghetikan si daemon dan jika sudah di hentikan tidak bakal muncul.
```
else if (argc == 3 && strcmp(argv[1], "stop") == 0 || strcmp(argv[1], "revert") == 0) {
    stop_mon(argv[2]);
}

```
![Screenshot 2025-04-17 135012](https://github.com/user-attachments/assets/9f6059db-f334-4909-8971-1a349258816a)

d. jika command fail di jalankan, maka user tersebut akan terblock dan tidak bisa melakukan apa-apa, dan pada log juga akan mencatat dengan setatus FAILED.
```
else if (argc == 3 && strcmp(argv[1], "fail") == 0) {
    jd_daemon();
    pantau(argv[2], 1);
}

```

e. ./debugmon revert untuk mnegembalikan user agar tidak terblock dan bisa menggunakan terminal kembai.
```
else if (argc == 3 && strcmp(argv[1], "stop") == 0 || strcmp(argv[1], "revert") == 0) {
    stop_mon(argv[2]);
}

```
