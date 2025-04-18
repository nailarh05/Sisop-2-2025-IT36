# SISOP-1-2024-IT36

Anggota Kelompok
|     Nrp    |                Nama              |
|-----       | -----                            |
|5027241106  | Mohammad Abyan Ranuaji           |
|5027241078  | Naila Raniyah Hanan              |


- [Soal & Penjelasan](#Soal&penjelasan)
  - [Soal 1](#soal-1)
  - [Soal 2](#soal-2)
  - [Soal 3](#soal-3)
  - [Soal 4](#soal-4)
 
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
