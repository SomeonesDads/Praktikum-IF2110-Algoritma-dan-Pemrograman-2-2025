module Matrix where 

-- UTILITY FUNCTIONS
konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

konsdotMatrix :: [[Int]] -> [Int] -> [[Int]]
konsoMatrix :: [Int] -> [[Int]] -> [[Int]]
isEmptyMatrix :: [[Int]] -> Bool

konsoMatrix e l = [e] ++ l
konsdotMatrix l e = l ++ [e]
isEmptyMatrix l = null l

-- NOTES: Semua Index dipastikan valid, yaitu tidak negatif dan tidak melebihi panjang list/Matrix

-- MATRIX MANIPULATION FUNCTIONS
-- TYPE: Matrix adalah [[Int]]
-- Dengan definisi type sebagai berikut, kita dapat mensubstitusi [[Int]] dengan Matrix
type Matrix = [[Int]]

-- addAtIndex :: Int -> [Int] -> Int -> [Int]
-- {addAtIndex x l i menambahkan elemen x pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [x] apabila l kosong
addAtIndex :: Int -> [Int] -> Int -> [Int]

addAtIndex x l i = 
    if isEmpty l then [x]
    else if i == 0 then konso x l
    else konso (head l) (addAtIndex x (tail l) (i-1))

-- deleteAtIndex :: [Int] -> Int -> [Int]
-- {deleteAtIndex l i menghapus elemen pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
deleteAtIndex :: [Int] -> Int -> [Int]

deleteAtIndex l i =
    if isEmpty l then []
    else if i == 0 then (tail l)
    else konso (head l) (deleteAtIndex (tail l) (i-1))
-- editAtIndex :: [Int] -> Int -> Int -> [Int]
-- {editAtIndex l i newValue mengubah elemen l pada posisi i dengan newValue}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
editAtIndex :: [Int] -> Int -> Int -> [Int]

editAtIndex l i newValue = 
    if isEmpty l then []
    else if i == 0 then konso newValue (tail l)
    else konso (head l) (editAtIndex (tail l) (i - 1) newValue)
-- addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {addMatrixElement m row col value menambahkan value pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix

addMatrixElement m row col value =
    if isEmptyMatrix m then []
    else if row == 0 then konsoMatrix (addAtIndex value (head m) col) (tail m)
    else konsoMatrix (head m) (addMatrixElement (tail m) (row - 1) col value)
-- deleteMatrixElement :: Matrix -> Int -> Int -> Matrix  
-- {deleteMatrixElement m row col menghapus elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
deleteMatrixElement :: Matrix -> Int -> Int -> Matrix

deleteMatrixElement m row col =
    if isEmptyMatrix m then []
    else if row == 0 then konsoMatrix (deleteAtIndex (head m) col) (tail m)
    else konsoMatrix (head m) (deleteMatrixElement (tail m) (row - 1) col)
-- editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {editMatrixElement m row col newValue mengubah elemen pada posisi (row,col) dengan newValue}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix

editMatrixElement m row col newValue =
    if isEmptyMatrix m then []
    else if row == 0 then konsoMatrix (editAtIndex (head m) col newValue) (tail m)
    else konsoMatrix (head m) (editMatrixElement (tail m) (row - 1) col newValue)



-- getMatrixElement :: Matrix -> Int -> Int -> Int
-- {getMatrixElement m row col mengambil elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan 0 apabila m kosong
getMatrixElement :: Matrix -> Int -> Int -> Int
getMatrixElement m row col = 
    if isEmptyMatrix m then 0
    else if row == 0 then getElementAtIndex (head m) col
    else getMatrixElement (tail m) (row - 1) col
-- printMatrix :: Matrix -> IO ()
-- {printMatrix m mencetak m dalam format yang mudah dibaca}
printMatrix :: Matrix -> IO ()
printMatrix [] = putStrLn "Empty m"
printMatrix m = mapM_ print m


getElementAtIndex :: [Int] -> Int -> Int

getElementAtIndex l i =
    if isEmpty l then 0
    else if i == 0 then head l
    else getElementAtIndex (tail l) (i - 1)