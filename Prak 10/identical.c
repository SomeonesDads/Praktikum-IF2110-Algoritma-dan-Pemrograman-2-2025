#include "bintree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Deskripsi:
 *  Mengembalikan true jika kedua binary tree identik, false jika tidak.
 * 
 * Spesifikasi:
 *  I.S.  : P dan Q terdefinisi (boleh NULL)
 *  F.S.  : Mengembalikan boolean true atau false.
 * 
 * Catatan:
 *  - Dua binary tree dikatakan identik apabila memiliki struktur yang sama dan
 *    nilai pada node-node yang bersesuaian juga sama.
 *
 * =======================================================
 * ----------------------- CONTOH 1 ----------------------
 * =======================================================
 *          (1)                 (1)
 *         /   \               /   \
 *       (2)   (3)           (2)   (3)
 * 
 * Output: true (1)
 * 
 * =======================================================
 * ----------------------- CONTOH 2 ----------------------
 * =======================================================
 *         (1)                 (1)
 *        /   \               /   \
 *      (2)   (3)           (3)   (2)
 * 
 * Output: false (0)
 */


boolean isIdentical(BinTree P, BinTree Q) {
    if (P == NULL && Q == NULL) 
        return true;
    if (P == NULL || Q == NULL) 
        return false;
    return (P->info == Q->info) && isIdentical(P->left, Q->left) && isIdentical(P->right, Q->right);
};

// int main(){
//     BinTree P;
//     BinTree Q;
//     // CreateTree(1, NewTree(2, NULL, NULL), NewTree(3, NULL, NULL), &P);
//     CreateTree(1, NULL, NULL, &P);
//     CreateTree(3, NULL, NULL, &Q);
//     // CreateTree(1, NewTree(2, NULL, NULL), NewTree(3, NULL, NULL), &Q);
//     // CreateTree(1, NewTree(2, NULL, NULL), NULL, &Q);
//     printf("%d", isIdentical(P, Q));
//     return 0;
// }