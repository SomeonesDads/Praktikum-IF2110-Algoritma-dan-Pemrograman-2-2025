#include "list.h"
#include <stdio.h>

/*
Nama file: merge-sort.c

Diberikan sebuah bilangan bulat n, kemudian diikuti dengan n buah bilangan bulat x1,x2,…,xn
Tugas Anda adalah mengurutkan seluruh bilangan tersebut secara menaik (ascending) menggunakan algoritma Merge Sort berbasis rekursif. 
Untuk menyelesaikan soal ini, Anda wajib menggunakan ADT List Rekursif yang diberikan untuk praktikum ini.

Format Masukan
    Satu bilangan bulat n (2≤n≤100).
    n bilangan bulat x1,x2,…,xn yang akan diurutkan.

Format Keluaran
    Menampilkan list setelah setiap stage merging pada merge sort menggunakan displayList yang kemudian diakhiri dengan newline.

Keterangan
    Indeks tengah pembagian list ditentukan dengan floor(L), dimana L adalah panjang list.

Contoh
Input 	        
6
5 3 1 4 2 5
Output
1 3
1 3 5
2 5
2 4 5
1 2 3 4 5 5
*/

void splitList(List l, List *left, List *right) {
    int n = length(l);
    int mid = n / 2;
    *left = NIL;
    *right = NIL;
    Address p = l;
    for (int i = 0; i < mid; i++) {
        *left = konsDot(*left, INFO(p));
        p = NEXT(p);
    }
    while (p != NIL) {
        *right = konsDot(*right, INFO(p));
        p = NEXT(p);
    }
}

List merge(List a, List b) {
    if (isEmpty(a)) return copy(b);
    if (isEmpty(b)) return copy(a);

    if (head(a) <= head(b)) {
        return konso(head(a), merge(tail(a), b));
    } else {
        return konso(head(b), merge(a, tail(b)));
    }
}

List mergeSort(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return copy(l);
    }
    List left, right;
    splitList(l, &left, &right);
    List sortedLeft = mergeSort(left);
    List sortedRight = mergeSort(right);
    List merged = merge(sortedLeft, sortedRight);
    displayList(merged);
    printf("\n");
    return merged;
}

int main(void) {
    int n;
    scanf("%d", &n);
    List l = NIL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l = konsDot(l, x);
    }
    mergeSort(l);
    return 0;
}
