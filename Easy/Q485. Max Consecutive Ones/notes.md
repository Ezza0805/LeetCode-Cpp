# Notes

## Yang Saya Pelajari

### 1. Perhatikan batas perulangan

Saat melakukan iterasi pada `vector`, batas perulangan harus menggunakan

```cpp
i < nums.size()
```

bukan

```cpp
i <= nums.size()
```

Karena indeks terakhir dari `vector` adalah `nums.size() - 1`.

Mengakses `nums[nums.size()]` akan berada di luar batas array (*out of bounds*) dan menyebabkan *undefined behavior*.

---

### 2. Bedakan operator assignment (`=`) dan comparison (`==`)

Saya sempat menulis

```cpp
final == temp;
```

Padahal operator `==` hanya digunakan untuk membandingkan dua nilai dan menghasilkan `true` atau `false`.

Untuk menyimpan nilai, saya harus menggunakan operator assignment.

```cpp
final = temp;
```

---

### 3. Reset nilai menggunakan assignment

Saat menemukan angka `0`, saya ingin mengembalikan penghitung ke awal.

Namun saya menulis

```cpp
temp == 0;
```

Kode tersebut hanya memeriksa apakah `temp` bernilai `0`, bukan mengubah nilainya.

Yang benar adalah

```cpp
temp = 0;
```

---

### 4. Pahami perbedaan assignment dan comparison

Kesalahan kedua dan ketiga memiliki penyebab yang sama, yaitu tertukar antara:

**Assignment**

```cpp
=
```

Digunakan untuk memberi nilai.

**Comparison**

```cpp
==
```

Digunakan untuk membandingkan dua nilai.

Kesalahan kecil seperti ini dapat membuat program tetap berhasil dikompilasi tetapi menghasilkan logika yang salah.

---

### 5. Periksa logika sebelum mencari optimasi

Permasalahan pada soal ini bukan berasal dari algoritmanya, melainkan dari kesalahan implementasi yang sederhana:

- Batas perulangan salah.
- Salah menggunakan operator.
- Variabel penghitung tidak pernah di-reset.

Saya belajar bahwa sebelum memikirkan optimasi, pastikan logika dasar program sudah benar.

---

## Kesalahan Pertama

Saya menggunakan

```cpp
for (int i = 0; i <= nums.size(); i++)
```

Akibatnya program mencoba mengakses indeks di luar ukuran `vector`.

Seharusnya menggunakan

```cpp
for (int i = 0; i < nums.size(); i++)
```

---

## Kesalahan Kedua

Saya menulis

```cpp
final == temp;
```

Padahal tujuan saya adalah memperbarui nilai `final` agar menyimpan jumlah `1` berurutan yang sedang dihitung.

Seharusnya menggunakan

```cpp
final = temp;
```

---

## Kesalahan Ketiga

Saat menemukan angka `0`, saya ingin mengosongkan penghitung.

Namun saya menulis

```cpp
temp == 0;
```

Padahal kode tersebut hanya melakukan perbandingan.

Seharusnya

```cpp
temp = 0;
```

---

## Ide Awal

Ide saya sejak awal adalah menggunakan dua variabel:

- `temp` untuk menghitung jumlah `1` yang sedang berurutan.
- `final` untuk menyimpan jumlah maksimum yang pernah ditemukan.

Ternyata logika tersebut sudah benar. Kesalahan saya bukan pada algoritma, melainkan pada implementasi, yaitu salah menentukan batas perulangan dan tertukar antara operator assignment (`=`) dengan operator comparison (`==`). Saya jadi belajar bahwa kesalahan kecil seperti ini dapat membuat seluruh program menghasilkan jawaban yang salah meskipun ide penyelesaiannya sudah tepat.