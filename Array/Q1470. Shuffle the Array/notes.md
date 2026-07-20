# Notes

## Yang Saya Pelajari

### 1. Gunakan parameter yang sudah disediakan

LeetCode sudah menyediakan parameter `n` yang menunjukkan jumlah elemen pada masing-masing bagian array (`x` dan `y`).Karena itu, Saya tidak perlu menghitung ulang titik tengah menggunakan variabel lain.

---

### 2. Hindari hardcode

Awalnya saya menggunakan

```cpp
i + 3
```

Pendekatan ini hanya bekerja jika `n = 3`.

Lebih baik menggunakan variabel yang sudah diberikan sehingga solusi dapat digunakan untuk semua test case.

---

### 3. Pahami pola indeks sebelum menulis kode

Saya menyadari bahwa memahami perpindahan indeks lebih penting daripada langsung membuat perulangan.

Dengan Menggambar posisi indeks 

Index : 0 1 2 | 3 4 5
Value : x x x | y y y

Saya dapat melihat dan menemukan solusi bahwa pasangan elemen berada pada:

nums[i]
nums[i + n]

Pendekatan ini membuat algoritma lebih mudah dipahami.
---

### 4. Perhatikan batas indeks

Mengakses indeks negatif seperti

```cpp
nums[-1]
```

akan menghasilkan *undefined behavior* pada C++.

---

### 5. Gunakan constraint sebagai acuan

Karena soal menjamin jumlah elemen selalu `2n`, saya tidak perlu membuat validasi tambahan terhadap ukuran array.

## Kesalahan pertama

Saya mencoba

```cpp
int split = nums.size()/2;
```

Padahal parameter `n` sudah menunjukkan titik pemisah antara bagian kiri (`x`) dan bagian kanan (`y`), sehingga variabel `split` menjadi tidak diperlukan.

## Kesalahan kedua

Saya membuat

```cpp
ans.push_back(angka(i-1));
```

Dapat mengakses indeks -1 pada vektor

## Ide awal

Awalnya saya ingin membuat variabel baru (`split`) sebagai pemisah antara [`x1,x2,...,xn,y1,y2,...,yn`], tetapi saya sadar `n` itu sebagai titik pemisah antara [`x1,x2,...,xn,y1,y2,...,yn`].
