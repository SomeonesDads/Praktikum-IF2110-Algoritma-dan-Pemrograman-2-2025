module ColumnOperations where 
{-
Nama File: ColumnOperations.hs

Header: module ColumnOperation where

Lengkapilah realisasi fungsi ColumnOperations dari file ColumnOperations.hs yang menerima masukan sebuah list of list (Matriks) Integer dan akan melakukan operasi reduce untuk setiap kolom yang ada di dalam matriks tersebut. Untuk setiap kolom operasi yang akan dilakukan adalah pencarian nilai maksimum kolom pertama, lalu pencarian nilai minimum untuk kolom selanjutnya, dan diikuti perhitungan jumlah untuk kolom berikutnya. Operasi ini akan dilakukan secara berulang - ulang dan sebagai gambaran, operasi yang dilakukan adalah max, min, sum, max, min, sum, dst.

Batasan:

- Matriks bisa kosong atau memiliki list - list yang kosong, contoh: [], [[],[],[]]

- Setiap list yang ada di dalam list parent pasti memiliki panjang yang sama

Contoh aplikasi fungsi dan hasilnya:

> columnOperations [[1,2,3],[4,5,6],[7,8,9]]

[7,2,18]


Keterangan: 7 adalah nilai maksimum kolom pertama (1, 4, 7), 2 adalah minimum kolom kedua (2, 5, 8), dan 18 adalah jumlah elemen - elemen di kolom ketiga (3, 6, 9).
-}
konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

-- REALISASI
konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

-- Lengkapi Fungsi di bawah ini
columnOperations :: [[Int]] -> [Int]
columnOperations l =
    if l == [] then []
    else if null (head l) then []
        else let 
            firstList = map head l
            operation1 = [maxint firstList minBound]
            in
                if length (head l) > 1 then
                    let 
                        secondList = map head (map tail l)
                        operation2 = konsdot operation1 (minint secondList maxBound)
                    in
                        if length (head l) > 2 then
                            let
                                thirdList = map head (map tail (map tail l))
                                operation3 = konsdot operation2 (sumint thirdList 0)
                            in
                                if length (head l) > 3 then
                                    operation3 ++ columnOperations (map tail (map tail (map tail l)))
                                else
                                    operation3
                        else 
                            operation2
                else
                    operation1

maxint :: [Int] -> Int -> Int
maxint l temp
    | null l = temp
    | head l > temp = maxint (tail l) (head l)
    | otherwise = maxint (tail l) temp

minint :: [Int] -> Int -> Int
minint l temp
    | null l = temp
    | head l < temp = minint (tail l) (head l)
    | otherwise = minint (tail l) temp
sumint :: [Int] -> Int -> Int
sumint l temp
    | null l = temp
    | otherwise = sumint (tail l) (head l + temp)