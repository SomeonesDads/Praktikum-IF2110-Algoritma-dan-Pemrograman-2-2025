module RunLengthEncoding where
{-
Nama File: RunLengthEncoding.hs

Header: module RunLengthEncoding where

Anda diminta mengimplementasikan fungsi runLengthEncoding yang menerima sebuah string dan mengembalikan list pasangan (elemen, jumlah) dimana jumlah adalah banyak elemen yang sama dan berurutan muncul.

Spesifikasi Fungsi:

runLengthEncoding :: String -> [(Char, Int)]

Contoh aplikasi fungsi:

> runLengthEncoding "aaaaabbc" 
[('a',5),('b',2),('c',1)]

> runLengthEncoding "" 
[]

> runLengthEncoding "a" 
[('a',1)]


Hint:

    Perhatikan bahwa String merupakan alias dari list of Char.
    Anda diperbolehkan untuk membuat fungsi helper.


-}
runLengthEncoding :: String -> [(Char, Int)]
runLengthEncoding s
  | null s    = []
  | otherwise = (head s, count+1) : runLengthEncoding rest
  where
    (count, rest) = countRun (head s) (tail s)

countRun :: Char -> String -> (Int, String)
countRun c s
  | null s          = (0, [])
  | head s == c     = let (n, rest) = countRun c (tail s)
                      in (n+1, rest)
  | otherwise       = (0, s)
