# Q1470 - Shuffle the Array

## 📖 Deskripsi Soal

Diberikan sebuah array integer `nums` yang terdiri dari `2n` elemen dengan format:

```text
[x1, x2, ..., xn, y1, y2, ..., yn]
```

Tugasnya adalah mengembalikan array baru dengan format:

```text
[x1, y1, x2, y2, ..., xn, yn]
```

### Contoh

```text
Input  : nums = [2,5,1,3,4,7], n = 3
Output : [2,3,5,4,1,7]
```

---

## 💡 Pendekatan Penyelesaian

Pada solusi ini saya membuat sebuah vector baru (`ans`) untuk menyimpan hasil pengurutan ulang elemen.

Array dibagi menjadi dua bagian:

```text
[x1, x2, ..., xn] [y1, y2, ..., yn]
```

Kemudian dilakukan perulangan sebanyak `n` kali. Pada setiap iterasi, saya mengambil satu elemen dari bagian kiri (`nums[i]`) dan satu elemen dari bagian kanan (`nums[i + n]`), lalu menambahkannya ke dalam `ans` menggunakan `push_back()`.

### Langkah-langkah

1. Membuat vector hasil (`ans`).
2. Melakukan perulangan sebanyak `n` kali.
3. Menambahkan elemen dari bagian kiri menggunakan:

```cpp
nums[i]
```

4. Menambahkan pasangan elemennya dari bagian kanan menggunakan:

```cpp
nums[i + n]
```

5. Mengembalikan vector `ans`.

---

## 📚 Konsep yang Dipelajari

- `vector`
- `push_back()`
- Parameter `n`
- Pola indeks pada array
- Analisis kompleksitas algoritma

---

## 🤔 Mengapa Menggunakan `i + n`?

Parameter `n` menunjukkan jumlah elemen pada masing-masing bagian array.

Misalnya:

```text
nums = [2,5,1,3,4,7]
n = 3
```

Maka posisi elemennya adalah:

```text
Index : 0 1 2 | 3 4 5
Value : 2 5 1 | 3 4 7
          x      y
```

Untuk setiap iterasi:

| i | nums[i] | nums[i+n] |
|---|---------|-----------|
|0|2|3|
|1|5|4|
|2|1|7|

Pendekatan ini membuat algoritma dapat digunakan untuk semua nilai `n` tanpa menggunakan angka tetap (*hardcode*).

---

## ⏱ Kompleksitas

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(n)** |
| Ruang Tambahan | **O(n)** (menggunakan vector baru untuk menyimpan hasil) |

---

## 🛠 Bahasa Pemrograman

- C++

---

## 🎯 Hasil

- ✅ Accepted
- Runtime : **0 ms**
- Time Complexity : **O(n)**

---

## 📌 Catatan

Kunci utama dalam soal ini bukanlah bentuk perulangannya, melainkan memahami hubungan indeks antara bagian kiri dan bagian kanan array.

Dengan memanfaatkan parameter `n`, solusi menjadi lebih fleksibel karena tidak bergantung pada jumlah elemen tertentu (misalnya menggunakan `i + 3`). Pendekatan ini membuat kode lebih mudah dipahami, lebih umum, dan dapat digunakan pada seluruh test case yang memenuhi constraint soal.