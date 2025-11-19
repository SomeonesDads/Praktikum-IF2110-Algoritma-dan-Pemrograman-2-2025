#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/*
Nama file: duplicates.c

Diberikan sebuah Sorted List berukuran N (N≥0). 
Hapus seluruh elemen dari list yang memiliki duplikat (kemunculan lebih dari satu kali). Implementasikan fungsi di file ini. Anda harus menggunakan ADT List Rekursif yang sudah diberikan pada praktikum ini.

Input: Satu list terurut dengan ukuran N (N≥0) yang mungkin memiliki duplikat

Output: List yang hanya berisi elemen unik (yang muncul tepat sekali).

Contoh : 
Masukan 	            Keluaran
[1, 2, 3, 3, 4, 4, 5]   [1, 2, 5]
[1,1,1] 	            []
*/

List removeDuplicates(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return copy(l);
    }

    List result = NIL;
    Address p = l;

    while (p != NIL) {
        int x = INFO(p);
        int count = 1;
        Address q = NEXT(p);
        while (q != NIL && INFO(q) == x) {
            count++;
            q = NEXT(q);
        }
        if (count == 1) {
            result = konsDot(result, x);
        }
        p = q;
    }

    return result;
}
