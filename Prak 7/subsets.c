#include <stdio.h>
/*
Nama file: subsets.c

Diberikan sebuah bilangan bulat n (menyatakan panjang array) dan sebuah array bilangan bulat terurut dengan elemen-elemen unik. Kembalikan semua kemungkinan subset dari array tersebut.
Set solusi tidak boleh mengandung subset yang duplikat. Dua subset dianggap duplikat jika memiliki elemen yang sama, meskipun urutannya berbeda (misalnya [1, 2] dan [2, 1]).

Semua subset harus ditampilkan dalam urutan yang benar, yaitu:

    Diurutkan berdasarkan panjang subset (jumlah elemen) dari yang paling sedikit ke paling banyak.

        Contoh: subset kosong [] ditampilkan terlebih dahulu.

    Untuk subset dengan panjang yang sama, urutan ditentukan secara leksikografis berdasarkan posisi elemen dalam array input.

Contoh urutan yang benar dapat dilihat pada contoh output dibawah.
Catatan: Solusi wajib menggunakan prosedur rekursif dalam penyelesaiannya.

Format Masukan

    Satu bilangan bulat n dengan batasan: 0 ≤ n ≤ 10.
    Baris berikutnya adalah bilangan bulat unik yang terurut membesar.

Format Keluaran

    Semua subset dari array, ditampilkan dalam urutan yang benar.
    Setiap subset ditulis dalam format daftar (contoh: [3,6]).
    Keluaran diakhiri dengan newline.

Contoh

Input

4 

3 6 8 9
*/

/* OBSERVASI
    Ada 2 approach, approach DP memilih untuk skip/insert (pelajari lebih aja lagi)
    Disini approachnya untuk menyetel len. len adalah panjang subset yang sekarang mau dibuat.
    Generate subset dari len = 0 -> len = n, setiap rekursi tambahkan tambahkan set[curindex -> n] ke subset[curlen], lalu panggil lagi fungsinya dengan curlen+1 dan curindex+1
    Ketika curlen == len, subset siap diprint. Ketika curindex >= n, looping sudah keluar batas dan bisa distop.
*/

void picknumber(int subset[], int len, int curindex, int n, int curlen, int set[]) {
    if (curlen == len) {
        printf("[");
        for (int i = 0; i < len; i++) {
            if (i != len - 1) printf("%d,", subset[i]);
            else printf("%d", subset[i]);
        }
        printf("]\n");
        return;
    }

    // kalau sisa elemen kurang dari yang dibutuhkan, stop
    if (curindex >= n) return;

    for (int i = curindex; i < n; i++) {
        subset[curlen] = set[i];
        picknumber(subset, len, i + 1, n, curlen + 1, set);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int set[n];
    for (int i = 0; i < n; i++) scanf("%d", &set[i]);

    // coba generate semua subset dari panjang 0 sampai n
    int subset[n];
    for (int len = 0; len <= n; len++) {
        picknumber(subset, len, 0, n, 0, set);
    }

    return 0;
}
