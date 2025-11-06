#include <stdio.h>

/* Nama file: lantai.c

Diberikan sebuah ruangan berukuran 2 x N (N > 0). dan ubin berukuran 2 x 1. Hitunglah berapa banyak cara menyusun ruangan tersebut menggunakan ubin berukuran 2 x 1. Ubin dapat diletakkan secara horizontal (1 x 2) atau vertikal (2 x 1). Soal ini harus diselesaikan dengan menggunakan rekursi. Jangan lupa newline di akhir output.

Board


Format Masukan

    Satu bilangan bulat n dengan 1 ≤ n ≤ 30.


Format Keluaran

    Satu bilangan bulat yang menyatakan banyak cara menyusun ubin pada lantai.
    Keluaran diakhiri dengan newline.


Contoh
Input (N)  	Output  	Penjelasan
3 	3 	Cara yang mungkin : 
- tiga ubin diletakkan secara vertikal.
- satu ubin secara vertikal dan dua ubin secara horizontal (2 cara)
1 	1 	Hanya terdapat satu cara        */

/* OBSERVASI
    Ketika ditambah 1 blok, ada 2 pilihan: VERTIKAL ATAU HORIZONTAL
    Ketika Vertikal, bisa menggunakan nilai f sebelumnya, f(n-1)
    Ketika Horizontal, dibutuhkan satu blok tambahan untuk melengkapi, menyisakan f(n-2)
    Sehingga f(n) = f(n-1) + f(n-2)
*/
int f(int n){
    if(n < 3) return n;
    else return f(n-1) + f(n-2);
}

int main(){
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}