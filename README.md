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
