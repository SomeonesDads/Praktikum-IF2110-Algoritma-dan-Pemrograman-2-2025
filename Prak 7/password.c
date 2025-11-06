#include "password.h"
#include <stdio.h>
#include <math.h>


int abs(int angka){return (angka < 0 ? angka*-1 : angka);} 
/**
 * Fungsi untuk mendapatkan panjang angka
 *
 * Hint: gunakan log10
 *
 * kembalikan -1 jika angka == 0
 */
int length(int angka){
    return (angka == 0 ? -1 : floor(log10(abs(angka))) + 1);
}

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 *
 * Contoh:
 * angka = 1234
 *
 * index = 2
 * return -> 2
 *
 * index = 1
 * return -> 3
 *
 * index = 0
 * return -> 4
 *
 * index = 4
 * return -> -1
 *
 * Hint: Gunakan operasi matematika power, module, dan div
 *
 * kembalikan -1 jika index > panjang atau index < 0 WOIII PANJANGNYA KAN 4!
 */
int getDigit(int angka, int index){
    if(index < 0 || index >= length(angka)) return -1;
    double b = pow(10, (index+1)); 
    int bint = b, a = ceil(b/10);
    int ans = (angka%bint) / a;
    return ans;
}

/**
 * Fungsi untuk menghapus digit ke-i dari kanan (misal: hapus index ke 2 dari 1234 -> 124) APANYA INI CO SUMPA LA KOK BEDA YG DIATAS SM YG DIBAWAH
 *
 *
 * Hint: Gunakan operasi matematika power, module, dan div untuk mendapatkan angka sebelah kiri dan kanan index lalu gabungkan dengan menggunakan perkalian power of 10 dan penjumlahan
 *
 * kembalikan angka yang sama jika index > panjang atau index < 0 GA SESUAI CO SUMPA APASI 
 */
int removeDigit(int angka, int index){
    int l = length(angka);
    if(index >= l || index < 0) return angka;
    else{
        index++;
        int newl = abs(index - l);
        int ans = angka/(pow(10,index));
        ans *= pow(10, index-1);
        ans += angka%(int)pow(10,index-1);
        return ans;
    }
}

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka
 * 
 * Hint:
 * - gunakan loop untuk melakukan iterasi ke seluruh digit di angka
 * - gunakan digit yang dipilih (dalam loop diatas) sebagai new current
 *   - current = 1, digit = 2 -> new current = 12
 * - hilangkan digit yang dipilih (dalam loop diatas) sebagai new angka
 *   - angka = 1234, digit yang dipilih = 2 -> new angka = 134
 * - panggil kembali fungsi rekursif
 */
void cariKombinasi(int angka, int current, int panjangAwal){
    if (length(angka) == -1) {
        printf("%d\n", current);
        return;
    }

    int l = length(angka);
    for (int i = 0; i < l; i++) {
        int digit_terpilih = getDigit(angka, i);
        int new_current = current * 10 + digit_terpilih;
        int new_angka = removeDigit(angka, i);
        cariKombinasi(new_angka, new_current, panjangAwal);
    }
}

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void findPassword(int angka){
    int panjangAwal = length(angka);
    cariKombinasi(angka, 0, panjangAwal);
}

