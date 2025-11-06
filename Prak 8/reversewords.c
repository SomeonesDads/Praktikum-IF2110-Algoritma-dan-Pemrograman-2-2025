#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
/*Nama File: reversewords.c

Anda diberikan sebuah sekuens yang terdiri atas n
buah kata, dipisahkan oleh satu atau lebih whitespace. Sekuens ini diakhiri oleh MARK berupa "." (titik) yang bukan merupakan bagian dari kata manapun.
Tugas anda adalah membalikkan setiap karakter pada setiap kata dengan tetap mempertahankan urutan kata awal. Setelah memproses semua kata, keluarkan setiap kata terbalik dengan dipisahkan oleh new line ("\n").
Format Masukan:
    Baris pertama berisi sebuah sekuens yang terdiri atas n buah kata dan dipisahkan oleh whitespace(s) (1≤n≤1000).
Format Keluaran:
    Keluaran berupa n buah baris, dengan baris ke-i berisi kata ke-i yang sudah dibalik.

Contoh Masukan dan Keluaran:
No  Masukan
1.  hello world abc def . 	
Keluaran
    olleh
    dlrow
    cba
    fed

2. example test case. 	
elpmaxe
tset
esac
Pastikan setiap output diakhiri oleh endline ("\n")!
Gunakan ADT mesin kata dan mesin karakter pada file berikut.
*/
int main(){
    STARTWORD();
    while(!EndWord){
        for(int i = currentWord.Length-1; i >= 0; i--){
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    return 0;
}
