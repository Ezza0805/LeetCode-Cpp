# Q485 - Max Consecutive Ones

## 📖 Deskripsi Soal

Diberikan sebuah array biner `nums` yang hanya berisi angka `0` dan `1`.

Tugasnya adalah mencari **jumlah maksimum angka `1` yang muncul secara berurutan** di dalam array.

### Contoh

```text
Input  : nums = [1,1,0,1,1,1]
Output : 3
```

Penjelasan:

Terdapat dua kelompok angka `1` yang berurutan:

```text
[1,1] dan [1,1,1]
```

Kelompok terpanjang memiliki panjang **3**.

---

## 💡 Pendekatan Penyelesaian

Pada solusi ini saya menggunakan dua variabel:

- `temp` untuk menghitung jumlah `1` yang sedang berurutan.
- `final` untuk menyimpan jumlah maksimum yang pernah ditemukan.

Program melakukan iterasi terhadap seluruh elemen pada array.

- Jika menemukan angka `1`, maka `temp` ditambah satu.
- Jika `temp` lebih besar daripada `final`, maka nilai `final` diperbarui.
- Jika menemukan angka `0`, maka `temp` dikembalikan menjadi `0` karena urutan angka `1` telah terputus.

---

## 📝 Langkah-langkah

1. Membuat variabel `temp` dan `final` dengan nilai awal `0`.
2. Melakukan iterasi dari indeks pertama hingga terakhir.
3. Jika elemen bernilai `1`, tambahkan nilai `temp`.
4. Jika `temp` lebih besar dari `final`, perbarui nilai `final`.
5. Jika elemen bernilai `0`, reset `temp` menjadi `0`.
6. Setelah iterasi selesai, kembalikan nilai `final`.

---

## 📚 Konsep yang Dipelajari

- Perulangan (`for`)
- Percabangan (`if`)
- Counter
- Assignment (`=`)
- Comparison (`==`)
- Batas indeks pada `vector`
- Analisis kompleksitas algoritma

---

## 🤔 Mengapa Menggunakan Dua Variabel?

Variabel `temp` digunakan untuk menghitung jumlah `1` yang sedang berurutan.

Sedangkan `final` digunakan untuk menyimpan jumlah maksimum yang pernah ditemukan.

Misalnya:

```text
nums = [1,1,0,1,1,1]
```

Prosesnya menjadi:

| Index | Nilai | temp | final |
|------:|------:|-----:|------:|
|0|1|1|1|
|1|1|2|2|
|2|0|0|2|
|3|1|1|2|
|4|1|2|2|
|5|1|3|3|

Nilai `temp` akan terus berubah mengikuti jumlah `1` yang sedang berurutan, sedangkan `final` hanya berubah ketika ditemukan urutan yang lebih panjang.

---

## ⏱ Kompleksitas

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(n)** |
| Ruang Tambahan | **O(1)** |

Program hanya melakukan satu kali iterasi terhadap array dan tidak menggunakan struktur data tambahan.

---

## 🛠 Bahasa Pemrograman

- C++

---

## 🎯 Hasil

- ✅ Accepted
- Runtime : **0 ms**
- Time Complexity : **O(n)**
- Space Complexity : **O(1)**

---

## 📌 Catatan

Awalnya saya mengira kesalahan terdapat pada logika algoritma, namun ternyata penyebabnya adalah kesalahan implementasi.

Beberapa kesalahan yang saya lakukan adalah:

- Menggunakan `i <= nums.size()` sehingga berpotensi mengakses indeks di luar batas array.
- Menulis `final == temp` padahal yang dibutuhkan adalah assignment (`final = temp`).
- Menulis `temp == 0` saat ingin mereset nilai penghitung, padahal seharusnya menggunakan `temp = 0`.

Dari soal ini saya belajar bahwa kesalahan kecil seperti penggunaan operator (`=` dan `==`) maupun batas perulangan dapat menyebabkan solusi menjadi salah, meskipun algoritma yang digunakan sudah benar.