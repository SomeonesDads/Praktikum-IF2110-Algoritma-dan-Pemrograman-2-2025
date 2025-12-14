/* File : bintree.h */
/* ADT pohon biner */
/* Implementasi pohon biner dengan representasi Address menggunakan pointer */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree){
  BinTree T = (BinTree)malloc(sizeof(BinTree));
    if (T != NULL) {
        ROOT(T) = root;
        LEFT(T) = left_tree;
        RIGHT(T) = right_tree;
    }
    return T;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
  *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val){
  return NewTree(val, NULL, NULL);
}

void deallocTreeNode(Address p){
  free(p);
}

boolean isTreeEmpty(BinTree p){
  return p == NULL;
}

boolean isOneElmt(BinTree p){
  return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p){
  return !isTreeEmpty(p) && isTreeEmpty(RIGHT(p)) && !isTreeEmpty(LEFT(p));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p){
    return !isTreeEmpty(p) && !isTreeEmpty(RIGHT(p)) && isTreeEmpty(LEFT(p));

}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p){
  return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

void printPreorder(BinTree p) {
  printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p) {
  printf("(");
  if (!isTreeEmpty(p)) {
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
  }
  printf(")");
}

void printPostorder(BinTree p) {
  printf("(");
    if (!isTreeEmpty(p))
    {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeUtil(BinTree p, int h, int level) {
    if (isTreeEmpty(p)) return;

    printf("%d\n", ROOT(p));
    if (!isTreeEmpty(LEFT(p))) {
        int i;
        for (i = 0; i < h * level; i++) {
            printf(" ");
        }
        printTreeUtil(LEFT(p), h, level + 1);
    }

    if (!isTreeEmpty(RIGHT(p))) {
        int i;
        for (i = 0; i < h * level; i++) {
            printf(" ");
        }
        printTreeUtil(RIGHT(p), h, level + 1);
    }
}

void printTree(BinTree p, int h) {
  printTreeUtil(p, h, 1);
}