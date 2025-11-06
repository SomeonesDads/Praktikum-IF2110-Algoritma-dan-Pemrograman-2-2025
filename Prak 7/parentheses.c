#include <stdio.h>
/*
Nama file: parentheses.c
Diberikan sebuah bilangan bulat n (jumlah pasangan kurung), hitung total banyaknya string kurung seimbang yang dapat dibentuk menggunakan tepat n buah '(' dan n buah ')'. Sebuah string disebut seimbang bila jumlah ')' dan '(' pada akhir string sama dan memiliki sekuens string kurung yang valid. Dengan kata lain, setiap kurung buka ('(') memiliki pasangan kurung tutup (')') yang tepat. 
Format Masukan
    Satu bilangan bulat n dengan batasan: 0 ≤ n ≤ 20.
Format Keluaran
    Satu bilangan bulat: total jumlah kombinasi kurung seimbang untuk n.
    Keluaran diakhiri dengan newline.

Contoh
Input 	Output 	Penjelasan Singkat
0       0
1       1       “()”.
2       2       “(())”, “()()”.
3       5       “((()))”, “(()())”, “(())()”, “()(())”, “()()()”.
4
*/


/*OBSERVASI
    Terlalu teoritis... pelajari catalan, implementasi dibawah hanya implementasi dari katalan
*/

#include <stdio.h>

unsigned long long memo[21];

unsigned long long f(int n) {
    if (n == 0) return 1;
    if (n<2) return n;
    unsigned long long s = 0;
    for (int i = 0; i < n; i++) s += f(i) * f(n - 1 - i);
    memo[n] = s;
    return s;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n == 0) { printf("0\n"); return 0; }
    for (int i = 0; i <= 20; i++) memo[i] = 0;
    unsigned long long ans = f(n);
    printf("%llu\n", ans);
    return 0;
}
