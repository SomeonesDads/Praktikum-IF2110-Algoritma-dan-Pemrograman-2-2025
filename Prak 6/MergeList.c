#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menggabungkan nilai-nilai di antara dua node bernilai 0
 * menjadi satu node dengan nilai hasil penjumlahan, dan menghapus seluruh node 0.
 *
 * I.S.  l terdefinisi, berisi minimal tiga elemen, dengan ketentuan:
 *      - Elemen pertama dan terakhir bernilai 0
 *      - Tidak ada dua node 0 yang bersebelahan
 *
 * F.S.  Setiap rentang elemen di antara dua 0 dijumlahkan menjadi satu node baru,
 *       dan list hasil tidak mengandung nilai 0 sama sekali.
 *
 * Contoh:
 * Jika l = [0,3,1,0,4,5,2,0], maka setelah mergeList(&l), l menjadi [4,11]
 * Jika l = [0,1,0,3,0,2,2,0], maka setelah mergeList(&l), l menjadi [1,3,4]
 *
 * Hint:
 * - Gunakan variabel untuk menampung hasil penjumlahan sementara
 * - Jangan lupa update FIRST(l) di akhir!
 */

void mergeList(List *l)
{
    /* KAMUS LOKAL */
    // TODO: Deklarasikan variabel yang diperlukan

    /* ALGORITMA */
    Address p;
    int segments = 0;
    int original = length(*l);
    p = FIRST(*l);
    p = NEXT(*l);
    int temp = 0;
    while (p != NULL)
    {
        if (INFO(p) == 0)
        {
            insertFirst(l, temp);
            temp = 0;
        }
        else
        {
            temp += INFO(p);
        }
        p = NEXT(p);
    }
    for (int i = 0; i < original; i++)
    {
        int temp;
        deleteLast(l, &temp);
    }

    for (int i = 0; i < (length(*l) - 1); i++)
    {
        int val;
        deleteLast(l, &val);
        insertAt(l, val, i);
    }
}
