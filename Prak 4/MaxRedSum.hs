module MaxRedSum where
{-
Nama File: MaxRedSum.hs

Header: module MaxRedSum where

Diberikan sebuah binary tree berisi bilangan bulat positif pada setiap node. Semua node awalnya berwarna putih. Anda dapat memilih beberapa node untuk diwarnai merah dengan aturan bahwa tidak boleh ada dua node merah yang saling bertetangga (yaitu parent dan child tidak boleh keduanya merah).

Fungsi maxRedSum harus mengembalikan jumlah maksimum nilai pada node-node yang diwarnai merah jika pewarnaan dilakukan secara optimal. Implementasikan fungsi maxRedSum pada file berikut.

Spesifikasi Fungsi:

> maxRedSum :: (BinTree Int) -> Int

Batasan:

    Nilai pada setiap node ke-i

adalah bilangan bulat positif dengan vi≤1000

    .
    1 ≤ n ≤ 12, dengan n adalah jumlah node dalam binary tree.

Contoh aplikasi fungsi:

-- Diberikan binary tree peta area:
--       3
--      / \
--     1   4
--        / \
--       2   6

> maxRedSum (Node 3 (Node 1 Empty Empty) (Node 4 (Node 2 Empty Empty) (Node 6 Empty Empty)))
11

Penjelasan:

Penjelasan: Pilihan optimal adalah mewarnai node bernilai 3, 2, dan 6 menjadi merah. Total = 3 + 2 + 6 = 11. Node 4 tidak boleh dipilih jika 2 atau 6 dipilih; demikian pula memilih 3 mencegah memilih anak-anaknya.

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
akar :: (BinTree Int) -> Int
{- akar p adalah akar dari p. Jika p adalah //L A R\\ maka akar p = A -}
akar (Node a l r) = a
left :: (BinTree Int) -> (BinTree Int)
{- left p adalah sub pohon kiri dari p. Jika p adalah //L A R\\ maka left p = L -}
left (Node a l r) = l
right :: (BinTree Int) -> (BinTree Int) 
{- right p adalah sub pohon kanan dari p. Jika p adalah //L A R\\ maka right p = R -}
right (Node a l r) = r

-- PREDIKAT
isTreeEmpty :: (BinTree Int) -> Bool
{- isTreeEmpty p true jika p adalah // \\ -}
isTreeEmpty Empty = True
isTreeEmpty (Node a l r) = False
isOneElmt :: (BinTree Int) -> Bool
{- isOneElmt p true jika p adalah //A\\ -}
isOneElmt p = not (isTreeEmpty p) && isTreeEmpty (left p) && isTreeEmpty (right p)

isUnerLeft :: (BinTree Int) -> Bool
{- isUnerLeft p true jika p hanya mengandung sub pohon kiri, P adalah //L A\\ -}
isUnerLeft p = not (isTreeEmpty p) && not (isTreeEmpty (left p)) && isTreeEmpty (right p)
isUnerRight :: (BinTree Int) -> Bool
{- isUnerRight p true jika p hanya mengandung sub pohon kanan, P adalah //A L\\ -}
isUnerRight p = not (isTreeEmpty p) && isTreeEmpty (left p) && not (isTreeEmpty (right p))
isBiner :: (BinTree Int) -> Bool
{- isBiner p true jika p mengandung sub pohon kiri dan sub pohon kanan, p adalah // L A R \\ -}
isBiner p = not (isTreeEmpty p) && not (isTreeEmpty (left p)) && not (isTreeEmpty (right p))

isExistLeft :: (BinTree Int) -> Bool
{- isExistLeft p true jika p mengandung sub pohon kiri -}
isExistLeft p = not (isTreeEmpty p) && not (isTreeEmpty (left p))
isExistRight :: (BinTree Int) -> Bool
{- isExistRight p true jika p mengandung sub pohon kanan -}
isExistRight p = not (isTreeEmpty p) && not (isTreeEmpty (right p))

-- Definisi dan Spesifikasi utama
maxRedSum :: (BinTree Int) -> Int
maxRedSum t
  | isTreeEmpty t = 0
  | isOneElmt t = akar t
  | otherwise =
      let
        l = left t
        r = right t
        val = akar t
        -- Kalau node ini diwarnai merah, anak-anaknya tidak boleh merah
        -- jadi kita ambil cucu (left dan right dari subtree kiri/kanan)
        withRed = val
          + (if isExistLeft t then maxRedSum (left (left t)) + maxRedSum (right (left t)) else 0)
          + (if isExistRight t then maxRedSum (left (right t)) + maxRedSum (right (right t)) else 0)

        -- Kalau node ini tidak diwarnai merah, maka anak-anaknya bisa diwarnai merah
        withoutRed = maxRedSum l + maxRedSum r
      in
        if withRed > withoutRed then withRed else withoutRed

-- maxRedSum menghitung jumlah maksimum nilai node berwarna merah dengan aturan pewarnaan sebagai berikut:
--   - Awalnya setiap node pada binary tree berwarna putih
--   - Anda dapat mewarnai sebuah node menjadi merah dengan syarat 
--     tidak ada node tetangganya (parent atau child) yang diwarnai merah. 
--     Dengan kata lain, tidak ada dua node warna merah yang bertetanggaan.
--   - Operasi pewarnaan node dapat dilakukan sebanyak mungkin selama tidak melanggar syarat lain
--
-- Batasan:
--   - Nilai dari sebuah node dipastikan bernilai positif
--   - 1 <= n <= 12 dengan n adalah banyak node
--
-- Contoh:
-- Diberikan pohon:
--       3
--      / \
--     1   4
--        / \
--       2   6
-- Dapat dibuktikan bahwa jumlah maksimum nilai node berwarna merah akan diperoleh
-- jika kita mewarnai node-node berikut menjadi merah: [3, 2, 6]
-- sehingga jawabannya adalah 3 + 2 + 6 = 11
--
-- Keterangan:
--   - Anda diperbolehkan menggunakan fungsi helper

-- TODO: implementasikan fungsi maxRedSum