# Notes

## Yang Saya Pelajari

### 1. Two Sum mencari **pasangan**, bukan menghitung semua kombinasi

Awalnya saya berpikir bahwa saya harus mencari semua kemungkinan pasangan menggunakan **nested loop**.

Padahal inti dari soal ini adalah:

1. Ambil satu angka.
2. Hitung angka yang dibutuhkan.

```cpp
int need = target - nums[i];
```

3. Cari apakah angka tersebut sudah pernah ditemukan.

Saya belajar bahwa fokusnya bukan mencari dua angka sekaligus, tetapi mencari **pasangan** dari angka yang sedang diproses.

---

### 2. `need` bukanlah jawaban

Saya sempat mengira bahwa hasil

```cpp
need = target - nums[i];
```

berarti saya sudah menemukan pasangan.

Padahal `need` hanyalah **angka yang sedang dicari**.

Contoh

```text
nums = [7,3,2,10]
target = 9
```

Saat membaca angka `7`

```cpp
need = 9 - 7;
```

Hasilnya

```text
2
```

Artinya saya **belum menemukan jawaban**, tetapi saya sedang mencari apakah angka `2` ada di dalam array.

---

### 3. Indeks pada `Seen` berbeda dengan indeks pada `nums`

Saya sempat membuat vector baru bernama `Seen`.

Masalahnya, saya mengembalikan indeks dari `Seen`.

```cpp
Index.push_back(i);
Index.push_back(j);
```

Padahal yang diminta LeetCode adalah indeks dari **array asli (`nums`)**, bukan indeks dari `Seen`.

Saya belajar bahwa ketika membuat array baru, indeksnya tidak lagi sama dengan array asal.

---

### 4. Nested loop menghasilkan kompleksitas `O(n²)`

Saya mencoba mempersempit data terlebih dahulu menggunakan vector `Seen`.

Ide tersebut memang dapat mengurangi jumlah data pada beberapa kasus.

Namun saya belajar bahwa analisis kompleksitas menggunakan **worst case**.

Jika ukuran `Seen` sama dengan ukuran `nums`, maka nested loop tetap memiliki kompleksitas

```text
O(n²)
```

---

### 5. Mengapa `unordered_map` membuat solusi menjadi `O(n)`

Saya sempat bertanya:

> Bagaimana cara mengetahui apakah angka yang saya butuhkan sudah ada?

Awalnya saya berpikir harus menggunakan nested loop.

Kemudian saya belajar bahwa `unordered_map` dapat menyimpan

```text
nilai -> indeks
```

Contohnya

```text
2 -> 0
7 -> 1
11 -> 2
```

Sehingga saya tidak perlu mencari satu per satu lagi.

---

### 6. Fungsi `find()` digunakan untuk mengecek apakah key sudah ada

Saya mempelajari baris berikut.

```cpp
seen.find(need) != seen.end()
```

Artinya

> Apakah angka `need` sudah pernah saya simpan?

Jika iya, berarti pasangan sudah ditemukan.

Jika tidak, saya simpan angka sekarang beserta indeksnya.

---

### 7. Urutan operasi sangat penting

Saya sempat bingung mengapa kode ditulis seperti ini.

```cpp
if (seen.find(need) != seen.end()) {
    return {seen[need], i};
}

seen[nums[i]] = i;
```

Ternyata pengecekan harus dilakukan **lebih dahulu**.

Jika angka saat ini langsung dimasukkan ke dalam `unordered_map`, ada kemungkinan sebuah elemen dipasangkan dengan dirinya sendiri.

---

### 8. Tidak perlu membuat vector `need`

Awalnya saya membuat

```cpp
vector<int> need;
```

Lalu mengisi seluruh nilai

```cpp
target - nums[i]
```

Saya belajar bahwa hal tersebut tidak diperlukan.

Cukup menggunakan variabel sementara.

```cpp
int need = target - nums[i];
```

Digunakan sekali, kemudian lanjut ke elemen berikutnya.

---

### 9. Compiler dan logika soal adalah dua hal yang berbeda

Saya mendapatkan error

```text
non-void function does not return a value in all control paths
```

Padahal pada soal dijelaskan bahwa solusi pasti ada.

Saya belajar bahwa compiler **tidak membaca deskripsi soal**.

Compiler hanya melihat bahwa ada kemungkinan fungsi selesai tanpa `return`.

Karena itu tetap perlu menambahkan

```cpp
return {};
```

di akhir fungsi.

---

## Kesalahan Pertama

Saya membuat vector `need` dan menganggap isinya merupakan jawaban.

```cpp
need.push_back(target - nums[i]);
```

Padahal `need` hanyalah angka yang sedang saya cari.

Saya tetap harus memeriksa apakah angka tersebut benar-benar ada.

---

## Kesalahan Kedua

Saya membuat vector `Seen` lalu mengembalikan indeks dari `Seen`.

```cpp
Index.push_back(i);
Index.push_back(j);
```

Padahal LeetCode meminta indeks dari `nums`.

Akibatnya output menjadi

```text
[0,1]
```

padahal seharusnya

```text
[0,3]
```

---

## Kesalahan Ketiga

Saya membandingkan

```cpp
nums[i] == need[j]
```

Padahal yang ingin saya ketahui adalah apakah pasangan dari `nums[i]` ada di dalam array.

Logika tersebut menyebabkan pasangan yang sama dapat ditemukan lebih dari satu kali.

---

## Kesalahan Keempat

Saya menggunakan nested loop seperti berikut.

```cpp
for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < nums.size(); j++) {
        ...
    }
}
```

Akibatnya pasangan seperti

```text
(0,3)
```

dan

```text
(3,0)
```

dihitung dua kali.

Saya belajar bahwa jika menggunakan brute force, loop kedua sebaiknya dimulai dari

```cpp
j = i + 1;
```

---

## Kesalahan Kelima

Saya sempat mengira bahwa menyaring data ke dalam vector `Seen` akan mengubah kompleksitas menjadi `O(n)`.

Ternyata tidak.

Karena pada kasus terburuk ukuran `Seen` dapat sama dengan ukuran `nums`, maka nested loop tetap memiliki kompleksitas `O(n²)`.

---

## Ide Awal

Ide awal saya adalah membuat vector `need` yang berisi hasil

```cpp
target - nums[i]
```

Kemudian saya mencoba mencari pasangan menggunakan nested loop.

Melalui proses debugging, saya memahami bahwa inti dari Two Sum bukan membuat array `need`, melainkan menyimpan angka yang sudah pernah dilihat beserta indeksnya menggunakan `unordered_map`.

Saya juga belajar bahwa optimasi bukan hanya mengurangi jumlah data, tetapi juga menghilangkan pencarian yang berulang. Dengan `unordered_map`, setiap angka cukup diproses satu kali sehingga kompleksitas berubah dari `O(n²)` menjadi rata-rata `O(n)`.

---

## Ringkasan Konsep

### Brute Force (`O(n²)`)

Untuk setiap angka:

- Periksa seluruh angka setelahnya.
- Jika jumlahnya sama dengan target, kembalikan indeksnya.

```cpp
nums[i] + nums[j] == target
```

---

### Optimal (`O(n)`)

Untuk setiap angka:

1. Hitung pasangan yang dibutuhkan.

```cpp
int need = target - nums[i];
```

2. Cek apakah pasangan tersebut sudah pernah disimpan.

```cpp
seen.find(need)
```

3. Jika ada, jawaban ditemukan.

4. Jika belum ada, simpan angka sekarang.

```cpp
seen[nums[i]] = i;
```

Saya belajar bahwa solusi `O(n)` bukan menghilangkan logika pencarian pasangan, melainkan mengganti pencarian berulang dengan struktur data yang dapat melakukan pencarian rata-rata dalam waktu konstan.