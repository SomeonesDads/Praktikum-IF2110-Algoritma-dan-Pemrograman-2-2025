module SecondLargest where
{-
Nama File: SecondLargest.hs

Header: module SecondLargest where

Anda diminta mengimplementasikan fungsi secondLargest yang menerima masukan berupa sebuah list bilangan bulat dan mengembalikan elemen terbesar kedua. List dipastikan memiliki setidaknya 2 elemen dan elemennya unik.

Spesifikasi Fungsi:

secondLargest :: [Int] -> Int

Contoh aplikasi fungsi:

> secondLargest [3, 5, 1, 4] 
4


Hint:

    Anda diperbolehkan membuat fungsi helper.


-}
secondLargest :: [Int] -> Int
secondLargest xs = findSecond xs (minBound, minBound)

-- Helper untuk mencari largest & second largest
findSecond :: [Int] -> (Int, Int) -> Int
findSecond xs (largest, second)
  | null xs   = second
  | otherwise =
      let x   = head xs
          rest = tail xs
      in if x > largest
            then findSecond rest (x, largest)
         else if x > second
            then findSecond rest (largest, x)
         else findSecond rest (largest, second)
