/* File: problem.c */
/* Implementasi fungsi untuk menyusun ulang linked list berdasarkan posisi ganjil dan genap */

#include "listlinier.h"
#include "listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menyusun ulang elemen-elemen linked list sehingga
 * semua elemen pada posisi ganjil (1, 3, 5, ...) muncul lebih dulu,
 * diikuti oleh elemen pada posisi genap (2, 4, 6, ...).
 * Urutan relatif antar elemen ganjil maupun antar elemen genap
 * harus tetap dipertahankan.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : Elemen-elemen dalam list l diubah urutannya secara in-place
 *          tanpa alokasi/dealokasi node baru.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah oddEvenLinkedList(&l), l menjadi [1,3,5,2,4]
 * Jika l adalah [10,20,30,40,50,60], maka hasilnya [10,30,50,20,40,60]
 * Jika l adalah [7], maka tetap [7]
 * Jika l adalah [], maka tetap []

*/

void oddEvenLinkedList(List *l)
{
    Address p = FIRST(*l);
    int ctr = 0;
    while (p!=NULL) {
        ctr++;
        p = NEXT(p);
    }
    Address genap[ctr/2];
    int i = 0;
    p = FIRST(*l);
    while(NEXT(p)!=NULL){
        genap[i] = NEXT(p);
        NEXT(p) = NEXT(NEXT(p));
        i++;
        p = NEXT(p);
    }
    p = FIRST(*l);
    while(NEXT(p)!=NULL){
        p = NEXT(p);
    }
    for(int i = 0; i < ctr/2; i++){
        NEXT(p) = genap[i];
        p = NEXT(p);
    }
    NEXT(p) = NULL;
}

