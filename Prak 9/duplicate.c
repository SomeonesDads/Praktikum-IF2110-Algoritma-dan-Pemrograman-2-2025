#include "list.h"
#include <stdio.h>

/**
 * Fungsi untuk menghilangkan elemen yang duplikat
 * 
 * Hilangkan elemen duplikat yang lebih depan
 * Misal:
 * 1 2 1 3 1 -> 2 3 1
 */
List removeDuplicate(List l) {
    if (isEmpty(l)) return NIL;
    List rest = removeDuplicate(tail(l));
    if (!search(rest, head(l))) {
        return konso(head(l), rest);
    }
    return rest;
}


int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    List l = NIL;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        l = konsDot(l, value);
    }

    List result = removeDuplicate(l);

    displayList(result);

    return 0;
}
