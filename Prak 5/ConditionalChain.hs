module ConditionalChain where
konso:: a -> [a] -> [a]
konso e l = e : l

konsDot:: [a] -> a -> [a]
konsDot l e = l ++ [e]


isEmpty:: [a] -> Bool
isEmpty l = null l

nbElement:: [a] -> Int
nbElement l = if isEmpty l then 0 else 1 + nbElement (tail l)

-- Deskripsi:
-- Fungsi `conditionalChain` menerima sebuah pasangan aturan yang terdiri dari
-- kondisi dan fungsi transformasi, serta sebuah list (bisa kosong).
-- Setiap elemen pada list akan dicek terhadap kondisi tersebut.
-- Jika elemen memenuhi kondisi, maka elemen tersebut akan diubah
-- menggunakan fungsi transformasi. Jika tidak, elemen dibiarkan tetap.

-- Contoh:
-- conditionalChain ((\x -> x < 0), (\x -> x - 1)) [-2, 0, 4] => [-3, 0, 4]

conditionalChain :: (a -> Bool, a -> a) -> [a] -> [a]
conditionalChain (fcond, ftrans) l = if isEmpty l then []
                                        else if(fcond (head l) ) then konso (ftrans (head l)) (conditionalChain (fcond, ftrans) (tail l))
                                            else konso (head l) (conditionalChain (fcond, ftrans) (tail l))
