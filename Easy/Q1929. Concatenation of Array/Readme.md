# Q1929. Concatenation of Array

## 📖 Deskripsi Soal

Diberikan sebuah array integer `nums` dengan panjang `n`. Tugasnya adalah membuat sebuah array baru yang merupakan hasil penggabungan (`concatenation`) dari `nums` dengan dirinya sendiri.

### Contoh

```text
Input  : [1, 2, 3]
Output : [1, 2, 3, 1, 2, 3]
```

---

## 💡 Pendekatan Penyelesaian

Pada solusi ini saya tidak membuat vector baru.

Sebagai gantinya, saya memanfaatkan `push_back()` untuk menambahkan setiap elemen asli ke bagian akhir vector yang sudah ada.

### Langkah-langkah

1. Menyimpan ukuran awal vector.

```cpp
int n = nums.size();
```

2. Melakukan perulangan sebanyak `n` kali.
3. Menambahkan setiap elemen menggunakan `push_back()`.
4. Mengembalikan vector yang telah diperbarui.

---

## 📚 Konsep yang Dipelajari

- `vector`
- `push_back()`
- `.size()`
- Analisis kompleksitas algoritma

---

## 🤔 Mengapa Harus Menyimpan Nilai `n`?

Fungsi `push_back()` akan menambah ukuran vector setiap kali dipanggil.

Jika perulangan ditulis seperti berikut:

```cpp
for (int i = 0; i < nums.size(); i++)
```

maka nilai `nums.size()` akan terus bertambah selama proses perulangan berlangsung, sehingga jumlah iterasi menjadi tidak sesuai dengan yang diinginkan.

Oleh karena itu, ukuran awal vector disimpan terlebih dahulu.

```cpp
int n = nums.size();
```

Dengan begitu, proses perulangan hanya berjalan sebanyak jumlah elemen awal.

---

## ⏱ Kompleksitas

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(n)** |
| Ruang Tambahan | **O(1)** (memodifikasi vector yang sudah ada) |

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

Solusi ini memodifikasi vector `nums` secara langsung dengan menambahkan elemen ke bagian akhirnya. Pendekatan ini menghasilkan kode yang lebih sederhana tanpa perlu membuat vector baru. Namun, pada beberapa kasus di dunia nyata, memodifikasi parameter input mungkin tidak selalu menjadi pilihan terbaik, sehingga perlu disesuaikan dengan kebutuhan dan spesifikasi program.