#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi yang melakukan pengurutan dengan urutan menaik jika asc = true
 * dan menurun jika asc = false
 *
 * I.S. List l terdefinisi dan berisi setidaknya 1 elemen
 * F.S. List l terurut secara urutan tertentu
 *
 * Contoh:
 * - Untuk l = [1, 5, 2, 3, 3], maka setelah sort(&l, true), l menjadi [1, 2, 3, 3, 5]
 */

void sort(List *l, boolean asc)
{
    Address p;
    p = FIRST(*l);
    int copy[length(*l)];
    int i = 0;
    while (p != NULL)
    {
        copy[i] = INFO(p);
        i++;
        p = NEXT(p);
    }
    int len = length(*l);
    if (asc)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (copy[i] < copy[j])
                {
                    int temp = copy[j];
                    copy[j] = copy[i];
                    copy[i] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (copy[i] > copy[j])
                {
                    int temp = copy[j];
                    copy[j] = copy[i];
                    copy[i] = temp;
                }
            }
        }
    }
    p = FIRST(*l);
    for (int i = 0; i < len; i++)
    {
        INFO(p) = copy[i];
        p = NEXT(p);
    }
}
