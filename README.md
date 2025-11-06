# 🧠 Praktikum Algoritma dan Pemrograman II

Repositori ini berisi kumpulan tugas dan latihan praktikum mata kuliah **IF1220 - Algoritma dan Pemrograman II** di **STEI-K ITB**.  
Seluruh kode dikerjakan menggunakan bahasa **Haskell** dan **C**, sesuai dengan modul dan topik praktikum tiap minggu.

---

## 📂 Struktur Direktori

Prak 1/ → ADT dasar dalam Haskell (Point, Tanggal, Mahasiswa)

Prak 2/ → Rekursi & List processing di Haskell

Prak 3/ → Operasi matriks dan array di Haskell

Prak 4/ → Binary Tree dan operasi rekursif di Haskell

Prak 5/ → Higher-order function & List comprehension di Haskell

Prak 6/ → ADT List Linier (Linked List) dalam C

Prak 7/ → Problem solving dengan stack, recursion, dan kombinatorik (C)

Prak 8/ → Mesin karakter & mesin kata (finite-state machine) dalam C


---

## 🧩 Bahasa Pemrograman

| Bahasa | Digunakan untuk | Tools/Compiler |
|---------|-----------------|----------------|
| **Haskell** | Praktikum 1–5 | GHC (Glasgow Haskell Compiler) |
| **C** | Praktikum 6–8 | GCC / Clang |

---

## ⚙️ Cara Menjalankan

### Haskell
Pastikan sudah menginstall `ghc`:
```bash
ghc -o program NamaFile.hs
./program

Atau langsung lewat GHCi:

ghci NamaFile.hs

C

Gunakan GCC untuk kompilasi:

gcc file1.c file2.c -o program
./program

Contoh untuk mesin kata:

gcc mesinkata.c mesinkarakter.c problem.c -o a
./a

🧪 Topik yang Dipelajari

    ADT dan Modularitas

        Pembuatan dan penggunaan tipe data abstrak (Point, Tanggal, dll).

    Rekursi dan List Processing

        Fungsi rekursif, manipulasi list, dan pattern matching di Haskell.

    Struktur Data Lanjut di Haskell

        Operasi pada Tree dan fungsi higher-order.

    Linked List dan Dynamic Memory

        Implementasi ADT list linier di C (alokasi, dealokasi, operasi elemen).

    Parsing & Mesin Kata

        Implementasi mesin karakter dan mesin kata di C untuk membaca input teks.

    Problem Solving

        Algoritma kombinatorik, rekursi lanjutan, dan simulasi stack/queue.

💻 Tools yang Digunakan

    Visual Studio Code (coding & debugging)

    GHC / GHCi untuk Haskell

    GCC (MSYS2) untuk C

    Git untuk version control

🧔 Author

Someonesdad
Mahasiswa STEI-K ITB, 2025

    Fokus pada pemahaman konsep algoritma, struktur data, dan praktik implementasi lintas bahasa (Haskell & C).

📜 Catatan

    Beberapa file a.exe adalah hasil kompilasi lokal di Windows (tidak disertakan di repo final).

    File problem.c atau telegram.c di tiap modul merupakan driver untuk mengetes fungsi dari ADT yang dibuat.

    Semua kode ditulis dan diuji secara mandiri selama praktikum.
