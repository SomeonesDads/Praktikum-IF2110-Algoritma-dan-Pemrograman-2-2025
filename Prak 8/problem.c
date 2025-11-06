/* File: problem.c */
/* Implementasi fungsi untuk mengecek apakah kalimat sesuai grammar dengan daftar objek */

/* Grammar yang digunakan:
 * <Kalimat> ::= <Subjek> <Predikat> <Objek> {, <Objek>}*
 *
 * Contoh kalimat valid:
 * - "aku beli buku."
 * - "aku beli buku, pensil, penggaris."
 * - "dia ambil tas, buku."
 *
 * Contoh tidak valid:
 * - "aku beli."
 * - "beli buku."
 * - "aku beli , pensil."
 */

 #include "mesinkata.h"
 #include "boolean.h"
 #include <stdio.h>
 #include <string.h>

 /* ====== FSM Parser ====== */
typedef enum {
    S_EXPECT_SUBJECT = 0,
    S_EXPECT_PREDICATE,
    S_EXPECT_FIRST_OBJECT,
    S_EXPECT_SEPARATOR_OR_END,
    S_EXPECT_OBJECT_AFTER_COMMA 
} State;

/* ====== Helper ====== */
/* Membandingkan dua kata secara case-insensitive */
int eqWordCStrInsensitive(Word w, const char *s) {
    int n = (int)strlen(s);
    if (w.Length != n) return 0;
    for (int i = 0; i < n; i++) {
        char cw = w.TabWord[i];
        if ('A' <= cw && cw <= 'Z') cw = (char)(cw - 'A' + 'a');
        char cs = s[i];
        if ('A' <= cs && cs <= 'Z') cs = (char)(cs - 'A' + 'a');
        if (cw != cs) return 0;
    }
    return 1;
}

int isSubjek(const Word w) {
    return eqWordCStrInsensitive(w, "aku")
        || eqWordCStrInsensitive(w, "kamu")
        || eqWordCStrInsensitive(w, "dia");
}

int isPredikat(const Word w) {
    return eqWordCStrInsensitive(w, "beli")
        || eqWordCStrInsensitive(w, "ambil");
}


 /* Silahkan tambahkan fungsi-fungsi helper lainnya jika perlu */
 
 /*
  * Fungsi utama untuk mengecek apakah kalimat sesuai grammar daftar objek
  * I.S. Mesin kata sudah siap digunakan (panggil STARTWORD() sebelumnya)
  * F.S. Mengembalikan true (1) jika kalimat valid, false (0) jika tidak
  *
  * Grammar: <Kalimat> ::= <Subjek> <Predikat> <Objek> {, <Objek>}*
  *
  * Contoh:
  *   Input  : "aku beli buku, pensil, penggaris."
  *   Output : 1
  *
  *   Input  : "aku beli , pensil."
  *   Output : 0 // tidak valid karena tidak ada objek setelah kata beli

  *   CONTOH LEBIH JELAS LIHAT PADA OLYMPIA
  *
  * Hint: Gunakan STARTWORD() untuk memulai pembacaan kata dan
  *       ADVWORD() untuk pindah ke kata berikutnya
  */
 
 /*
  * Hint (secukupnya):
  *
  * A. Pakai FSM (Finite State Machine) seperti yang sudah didefinisikan di atas
  *
  * B. Transisi inti:
  *    SUBJEK → PREDIKAT → OBJEK
  *
  *    Setelah objek:
  *    - Jika objek berkoma (melekat) → S_EXPECT_OBJECT_AFTER_COMMA
  *    - Jika tanpa koma → S_EXPECT_SEPARATOR_OR_END
  *
  *    Di S_EXPECT_SEPARATOR_OR_END, satu-satunya token valid
  *    (kalau belum MARK) adalah koma → lanjut ke S_EXPECT_OBJECT_AFTER_COMMA.
  *
  *    Di S_EXPECT_OBJECT_AFTER_COMMA, token wajib objek (boleh lagi berkoma).
  *
  * C. Kondisi akhir valid:
  *    Loop selesai (MARK terbaca → EndWord == true) dan state terakhir adalah
  *    S_EXPECT_SEPARATOR_OR_END serta setidaknya satu objek sudah terbaca.
  *
  * D. Helper minimal yang disarankan:
  *    - isCommaToken(Word w) → w.Length == 1 && w.TabWord[0] == ','.
  *    - isObjToken(Word w, int *hasTrailingComma):
  *        * Jika token berakhir ',', set *hasTrailingComma = 1 dan cek sisa hurufnya alfabet semua.
  *        * Jika tidak berakhir ',', set *hasTrailingComma = 0 dan cek semua alfabet.
  *        * Token "," bukan objek.
  */
 
 int cfg_parser() {
     STARTWORD();
     State s = S_EXPECT_SUBJECT;
     int masukobjek = 0;
     while(!EndWord){
        if(s == 0){
            // printf("A\n");
            if(!isSubjek(currentWord)) return 0;
            s = S_EXPECT_PREDICATE;
        }
        else if(s==1){
            // printf("b\n");
            if(!isPredikat(currentWord)) return 0;
            s = S_EXPECT_FIRST_OBJECT;
        }
        else if(s==2 || s==4){
            if(currentWord.TabWord[0] == ',' && !masukobjek) return 0;
            masukobjek = 1;
            // printf("C\n");
            for (int i = 0; i < currentWord.Length; i++) {
                char cw = currentWord.TabWord[i];
                if(cw == ','){
                    s = S_EXPECT_OBJECT_AFTER_COMMA; break;
                }
                else if (!(('a' <= cw && cw <= 'z') || ('A' <= cw && cw <= 'Z'))) return 0;
            }       
            if(currentWord.TabWord[currentWord.Length-1] != ',') s = S_EXPECT_SEPARATOR_OR_END;
        }
        else if(s==3){
            if(!(currentWord.Length == 1 && currentWord.TabWord[0] == ',')) return 0;
            s = S_EXPECT_OBJECT_AFTER_COMMA; 
        }
        ADVWORD();
    }
    
    return (s == 3 && EndWord == true);
}

int main(){
    printf(cfg_parser() ? "1" : "0");
    return 0;
}