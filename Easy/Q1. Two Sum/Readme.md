# Q1 - Two Sum

## 📖 Deskripsi Soal

Diberikan sebuah array integer `nums` dan sebuah bilangan `target`.

Tugasnya adalah mengembalikan **dua indeks** dari elemen pada array yang jika dijumlahkan menghasilkan nilai `target`.

Diasumsikan bahwa:

- Setiap input memiliki **tepat satu solusi**.
- Setiap elemen hanya boleh digunakan **satu kali**.

### Contoh

```text
Input  : nums = [2,7,11,15], target = 9
Output : [0,1]
```

Penjelasan:

```text
nums[0] + nums[1]
= 2 + 7
= 9
```

Sehingga indeks yang dikembalikan adalah

```text
[0,1]
```

---

## 💡 Pendekatan Penyelesaian

Awalnya saya mencoba menyelesaikan soal ini menggunakan **nested loop** karena berpikir setiap elemen harus dibandingkan dengan seluruh elemen lainnya.

Kemudian saya mempelajari solusi yang lebih optimal menggunakan `unordered_map`.

Ide utamanya adalah:

1. Membaca array satu kali dari kiri ke kanan.
2. Menghitung angka pasangan yang dibutuhkan.

```cpp
int need = target - nums[i];
```

3. Mengecek apakah angka tersebut sudah pernah ditemukan sebelumnya.
4. Jika sudah ditemukan, langsung mengembalikan kedua indeks.
5. Jika belum, simpan angka sekarang beserta indeksnya.

Dengan cara ini, pencarian tidak perlu dilakukan berulang kali.

---

## 📝 Langkah-langkah

1. Membuat `unordered_map<int, int>` untuk menyimpan pasangan **nilai → indeks**.
2. Melakukan iterasi terhadap seluruh elemen array.
3. Menghitung nilai pasangan yang dibutuhkan (`need`).
4. Mengecek apakah `need` sudah ada di dalam `unordered_map`.
5. Jika ada, kembalikan indeks yang tersimpan dan indeks saat ini.
6. Jika belum ada, simpan nilai sekarang beserta indeksnya.
7. Lanjutkan hingga pasangan ditemukan.

---

## 📚 Konsep yang Dipelajari

- Array
- Hash Table (`unordered_map`)
- One Pass Algorithm
- Key-Value Pair
- Pencarian data (`find()`)
- Kompleksitas algoritma
- Brute Force vs Optimized Solution

---

## 🤔 Mengapa Menggunakan `unordered_map`?

Pada solusi brute force, setiap elemen harus dibandingkan dengan seluruh elemen lainnya.

Misalnya

```text
2

↓

cek 7
cek 11
cek 15
```

Kemudian

```text
7

↓

cek 11
cek 15
```

Proses tersebut menyebabkan kompleksitas menjadi **O(n²)**.

Dengan `unordered_map`, saya cukup menyimpan angka yang sudah pernah ditemukan.

Misalnya

```text
2 -> 0
7 -> 1
11 -> 2
```

Saat menemukan angka baru, saya hanya perlu bertanya:

> Apakah pasangan angka ini sudah pernah saya simpan?

Jika jawabannya **ya**, maka solusi langsung ditemukan tanpa melakukan pencarian menggunakan nested loop.

---

## 🔄 Ilustrasi Proses

Misalnya

```text
nums = [2,7,11,15]
target = 9
```

| Iterasi | Angka | need | Isi `seen` | Hasil |
|---------:|------:|-----:|------------|--------|
|1|2|7|{}|Simpan `2 -> 0`|
|2|7|2|{2 → 0}|Pasangan ditemukan → Return `{0,1}`|

Perhatikan bahwa program berhenti setelah menemukan pasangan sehingga tidak perlu memeriksa angka `11` maupun `15`.

---

## 🔍 Brute Force vs Optimized

### Brute Force

Untuk setiap elemen, program memeriksa seluruh elemen setelahnya.

```cpp
for (...) {
    for (...) {
        if (nums[i] + nums[j] == target)
    }
}
```

Kompleksitas waktu:

```text
O(n²)
```

---

### Optimized

Setiap elemen diproses **satu kali**.

```cpp
int need = target - nums[i];

if (seen.find(need) != seen.end()) {
    return {seen[need], i};
}

seen[nums[i]] = i;
```

Kompleksitas waktu rata-rata:

```text
O(n)
```

---

## ⏱ Kompleksitas

### Brute Force

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(n²)** |
| Ruang Tambahan | **O(1)** |

---

### Optimized (`unordered_map`)

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(n)** *(rata-rata)* |
| Ruang Tambahan | **O(n)** |

`unordered_map` membutuhkan memori tambahan untuk menyimpan angka yang telah diproses.

---

## 🛠 Bahasa Pemrograman

- C++

---

## 🎯 Hasil

- ✅ Accepted
- Pendekatan Brute Force : **O(n²)**
- Pendekatan Optimized : **O(n)**
- Menggunakan `unordered_map`

---

## 📌 Catatan

Soal ini mengajarkan saya bahwa optimasi algoritma tidak selalu berarti membuat logika yang lebih rumit, tetapi sering kali menggunakan struktur data yang tepat.

Pada awalnya saya mencoba:

- Membuat vector `need`.
- Membuat vector `Seen`.
- Menggunakan nested loop untuk mencari pasangan.
- Menyaring data agar jumlah iterasi berkurang.

Namun saya menyadari bahwa semua pendekatan tersebut masih melakukan pencarian berulang sehingga kompleksitasnya tetap **O(n²)** pada kasus terburuk.

Saya juga sempat melakukan beberapa kesalahan, seperti:

- Mengembalikan indeks dari vector `Seen`, bukan dari `nums`.
- Menganggap `need` adalah jawaban, padahal `need` hanyalah angka yang sedang dicari.
- Mengira menyaring data akan otomatis mengubah kompleksitas menjadi **O(n)**.
- Bingung membedakan indeks pada array baru dengan indeks pada array asli.

Dari soal ini saya belajar bahwa inti dari solusi optimal bukan membuat array tambahan, melainkan **menyimpan informasi yang sudah pernah ditemukan** agar pencarian berikutnya dapat dilakukan dalam waktu konstan menggunakan `unordered_map`. Ini menjadi pengenalan pertama saya terhadap konsep **Hash Table** dalam C++.