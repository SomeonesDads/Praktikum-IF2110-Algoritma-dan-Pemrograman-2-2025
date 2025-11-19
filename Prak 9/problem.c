    /* File: problem.c */
    /* Implementasi fungsi untuk merotasi linked list ke kanan sebanyak k posisi */

    #include "list.h"
    #include <stdio.h>
    #include <stdlib.h>

    /*
    * Fungsi untuk merotasi linked list ke kanan sebanyak k posisi.
    * Rotasi ke kanan artinya elemen-elemen terakhir dipindahkan ke depan.
    *
    * I.S.  : l terdefinisi, mungkin kosong; k >= 0
    * F.S.  : Mengembalikan list baru yang merupakan hasil rotasi l sebanyak k posisi ke kanan.
    *         List asli l tidak dimodifikasi (fungsional approach).
    *         Jika k lebih besar dari panjang list, gunakan k modulo panjang list.
    *
    * Contoh:
    * Jika l adalah [1,2,3,4,5] dan k=2, maka hasil [4,5,1,2,3]
    * Jika l adalah [1,2,3,4,5] dan k=0, maka hasil [1,2,3,4,5]
    * Jika l adalah [1,2,3,4,5] dan k=7, maka hasil [4,5,1,2,3] (karena 7 % 5 = 2)
    */

List rotateRight(List l, int k){
    if (isEmpty(l)) return NIL;
    int n = length(l);
    k %= n;
    if (k == 0) return copy(l);     
    Address p = l;
    for (int i = 1; i < n - k; i++) {
        p = NEXT(p);
    }
    Address right = NEXT(p);
    List rlist = NIL;
    Address q = right;
    while (q != NIL) {
        rlist = konsDot(rlist, INFO(q));   
        q = NEXT(q);
    }
    List clist = NIL;
    q = l;
    while (q != right) {
        clist = konsDot(clist, INFO(q));    
        q = NEXT(q);
    }
    return concat(rlist, clist);           
}


    // int main()
    // {
    //     Address l;
    //     // l = newNode(1);
    //     // l = konsDot(l, 2);
    //     // l = konsDot(l, 3);
    //     // l = konsDot(l, 4);
    //     // l = konsDot(l, 5);
    //     // l = konsDot(l, 6);
    //     displayList(l);
    //     displayList(rotateRight(l, 2));
    //     return 0;
    // }