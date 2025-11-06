module ThreeTree where

{-
Nama File: ThreeTree.hs

Header: module ThreeTree where

Di sebuah desa, tumbuh sebuah pohon magis bernama ThreeTree. Dengan memberikan persembahan berupa biji apel, pohon ini dapat mengabulkan permintaan para penduduk desa. Jumlah biji apel yang diberikan pada satu kali persembahan harus merupakan kelipatan 3. Jika tidak, pohon ini malah akan memberikan kutukan kepada para penduduk desa.

Karena banyak penduduk desa yang ingin memberikan persembahan, tugasmu adalah menyaring persembahan tersebut dengan hanya menyisakan jumlah biji apel yang merupakan kelipatan 3. Untuk itu, kamu perlu mengimplementasikan fungsi threeTree yang menerima sebuah list bilangan bulat L dan mengembalikan list baru yang hanya berisi bilangan-bilangan kelipatan 3 dari L.

Spesifikasi Fungsi:

threeTree :: [Int] -> [Int]

Contoh aplikasi fungsi:

> threeTree [1, 2, 3, 4, 5, 6]
[3, 6]


Keterangan:

    Proses filter tidak mengubah urutan dari list
-}
threeTree :: [Int] -> [Int]
threeTree l = if length l == 0 then []
                else if head l `mod` 3 == 0 then [head l] ++ threeTree (tail l)
                else threeTree (tail l)