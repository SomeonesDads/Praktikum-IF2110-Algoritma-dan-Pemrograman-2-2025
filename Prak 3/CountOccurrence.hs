module CountOccurrence where

-- count(ListOfList, n) menghitung berapa kali integer n muncul di dalam sebuah list of list.
-- CONTOH: count [[1,2,1],[3],[1,4]] 1 menghasilkan 3
count :: [[Int]] -> Int -> Int
-- TODO : implementasi fungsi count 
count l n =
    if null l then 0
    else ((countList (head l) n) + (count (tail l) n))

countList :: [Int] -> Int -> Int

countList l x = 
    if null l then 0
    else if (head l == x) then 1 + countList (tail l) x
         else countList (tail l) x


