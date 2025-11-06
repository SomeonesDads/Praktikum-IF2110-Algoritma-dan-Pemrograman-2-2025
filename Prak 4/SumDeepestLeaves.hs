module SumDeepestLeaves where
{-
Nama File: SumDeepestLeaves.hs

Header: module SumDeepestLeaves where

sumDeepestLeaves(t) mengembalikan jumlah nilai semua daun yang berada pada kedalaman (level) maksimum dari pohon biner t.

Anda diminta mengimplementasikan fungsi sumDeepestLeaves pada file berikut.

Spesifikasi Fungsi:

> sumDeepestLeaves :: (BinTree Int) -> Int

Batasan:

    Jumlah node dalam pohon berada dalam rentang [1, 10^4]
    1 <= Node.val <= 100

Contoh aplikasi fungsi:

-- ghci> let tree1 = Node 1 (Node 2 (Node 4 (Node 7 Empty Empty) Empty) (Node 5 Empty Empty)) (Node 3 Empty (Node 6 Empty (Node 8 Empty Empty)))
-- ghci> sumDeepestLeaves tree1
-- 15

--    Penjelasan tree1:
--        1      <- level 1
--       / \
--      2   3    <- level 2
--     / \   \
--    4   5   6  <- level 3
--   /         \
--  7           8 <- level 4 (daun terdalam)
--  Daun terdalam: [7, 8], jumlah = 7 + 8 = 15


-- ghci> let tree2 = Node 6 (Node 7 (Node 2 (Node 9 Empty Empty) Empty) (Node 7 (Node 1 Empty Empty) (Node 4 Empty Empty))) (Node 8 (Node 1 Empty Empty) (Node 3 Empty (Node 5 Empty Empty)))
-- ghci> sumDeepestLeaves tree2
-- 19
--
--    Penjelasan tree2:
--        6      <- level 1
--       / \
--      7   8    <- level 2
--     / \ / \
--    2  7 1  3  <- level 3
--   /  / \    \
--  9  1   4    5 <- level 4 (daun terdalam)
--  Daun terdalam: [9, 1, 4, 5], jumlah = 9 + 1 + 4 + 5 = 19


ghci> sumDeepestLeaves Empty
0

ghci> sumDeepestLeaves (Node 5 Empty Empty)
5

Keterangan:

    Anda diperbolehkan menggunakan fungsi helper.
-}
data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
-- Definisi dan Spesifikasi utama
akar  :: BinTree Int -> Int
left  :: BinTree Int -> BinTree Int
right :: BinTree Int -> BinTree Int

-- Realisasi
akar Empty          = error "akar: pohon kosong tidak punya akar"
akar (Node v _ _)   = v

left Empty          = error "left: pohon kosong tidak punya subpohon kiri"
left (Node _ l _)   = l

right Empty         = error "right: pohon kosong tidak punya subpohon kanan"
right (Node _ _ r)  = r

-- PREDIKAT
-- Definisi dan Spesifikasi utama
isTreeEmpty  :: BinTree a -> Bool
isOneElmt    :: BinTree a -> Bool    
isExistLeft  :: BinTree a -> Bool
isExistRight :: BinTree a -> Bool
isUnerLeft   :: BinTree a -> Bool    
isUnerRight  :: BinTree a -> Bool     
isBiner      :: BinTree a -> Bool     

-- Realisasi
isTreeEmpty Empty                = True
isTreeEmpty _                    = False

isOneElmt (Node _ Empty Empty)   = True
isOneElmt _                      = False

isExistLeft (Node _ l _)         = not (isTreeEmpty l)
isExistLeft _                    = False

isExistRight (Node _ _ r)        = not (isTreeEmpty r)
isExistRight _                   = False

isUnerLeft (Node _ l r)          = not (isTreeEmpty l) && isTreeEmpty r
isUnerLeft _                     = False

isUnerRight (Node _ l r)         = isTreeEmpty l && not (isTreeEmpty r)
isUnerRight _                    = False

isBiner (Node _ l r)             = not (isTreeEmpty l) && not (isTreeEmpty r)
isBiner _                        = False

-- DEFINISI DAN SPESIFIKASI UTAMA
sumDeepestLeaves :: (BinTree Int) -> Int
-- { sumDeepestLeaves(t) mengembalikan jumlah nilai semua daun yang berada
--   pada kedalaman (level) maksimum dari pohon biner t. }
-- TODO: Implementasikan fungsi sumDeepestLeaves secara rekursif
sumDeepestLeaves p
    | isTreeEmpty p = 0
    | isOneElmt p = akar p
    | not ((akar p) == 0) = (sumTree (pruneTree p (level p 0)))
-- CONTOH APLIKASI FUNGSI
-- ghci> let tree1 = Node 1 (Node 2 (Node 4 (Node 7 Empty Empty) Empty) (Node 5 Empty Empty)) (Node 3 Empty (Node 6 Empty (Node 8 Empty Empty)))
-- ghci> sumDeepestLeaves tree1
-- 15
--    Penjelasan tree1:
--        1      <- level 1
--       / \
--      2   3    <- level 2
--     / \   \
--    4   5   6  <- level 3
--   /         \
--  7           8 <- level 4 (daun terdalam)
--  Daun terdalam: [7, 8], jumlah = 7 + 8 = 15

-- ghci> let tree2 = Node 6 (Node 7 (Node 2 (Node 9 Empty Empty) Empty) (Node 7 (Node 1 Empty Empty) (Node 4 Empty Empty))) (Node 8 (Node 1 Empty Empty) (Node 3 Empty (Node 5 Empty Empty)))
-- ghci> sumDeepestLeaves tree2
-- 19
--    Penjelasan tree2:
--        6      <- level 1
--       / \
--      7   8    <- level 2
--     / \ / \
--    2  7 1  3  <- level 3
--   /  / \    \
--  9  1   4    5 <- level 4 (daun terdalam)
--  Daun terdalam: [9, 1, 4, 5], jumlah = 9 + 1 + 4 + 5 = 19

-- -- Definisi dan Spesifikasi Utama
pruneTree :: BinTree Int -> Int -> BinTree Int
-- -- {- pruneTree p d menghasilkan pohon p yang dipangkas sehingga 
-- --    kedalaman pohon tidak lebih dari d.
-- --    Kedalaman akar adalah 1.
-- -- -}
pruneTree p d
    |  d == 1 = makeBinTree (akar p) Empty Empty
    | (d > 1) && isOneElmt p = makeBinTree 0 Empty Empty 
    | (d > 1) && isBiner p = makeBinTree 0 (pruneTree (left p) (d-1)) (pruneTree (right p) (d-1))
    | (d > 1) && isUnerLeft p = (pruneTree (left p) (d-1)) 
    | (d > 1) && isUnerRight p = (pruneTree (right p) (d-1))

level :: BinTree Int -> Int -> Int 
level p l 
    | isOneElmt p = l+1
    | isUnerLeft p = level (left p) (l+1) 
    | isUnerRight p = level (right p) (l+1) 
    | isBiner p = if ((level (right p) (l+1)) > (level (left p) (l+1))) then level (right p) (l+1) 
                    else level (left p) (l+1) 

sumTree :: BinTree Int -> Int
sumTree p
    | isOneElmt p = akar p
    | isBiner p = (akar p) + (sumTree (left p)) + (sumTree (right p))
    | isUnerLeft p = (akar p) + (sumTree (left p))
    | isUnerRight p = (akar p) + (sumTree (right p))