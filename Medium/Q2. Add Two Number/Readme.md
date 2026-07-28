# Q2. Add Two Numbers

## 📖 Deskripsi Soal

Diberikan dua buah linked list non-kosong `l1` dan `l2` yang merepresentasikan dua bilangan bulat non-negatif. Setiap node menyimpan satu digit angka, dan digit disimpan dalam urutan terbalik (*reverse order*).

Tugasnya adalah menjumlahkan kedua bilangan tersebut dan mengembalikan hasilnya dalam bentuk linked list dengan format yang sama.

### Contoh

```text
Input  : l1 = [2,4,3], l2 = [5,6,4]
Output : [7,0,8]

Penjelasan:
342 + 465 = 807
```

---

## 💡 Pendekatan Penyelesaian

Pada solusi ini saya membangun sebuah linked list baru sebagai hasil penjumlahan.

Setiap pasangan node dijumlahkan satu per satu. Apabila hasil penjumlahan menghasilkan dua digit, maka digit puluhan disimpan sebagai **carry** untuk ditambahkan pada proses penjumlahan node berikutnya, sedangkan digit satuannya disimpan ke dalam node hasil.

Solusi ini juga menangani kondisi ketika panjang kedua linked list berbeda.

### Langkah-langkah

1. Membuat pointer `hasilHead` dan `hasilTail` sebagai awal dan akhir linked list hasil.
2. Melakukan perulangan selama masih terdapat node pada salah satu linked list.
3. Menjumlahkan nilai node dari `l1` dan `l2`.
4. Menambahkan nilai `carry` apabila masih ada.
5. Memisahkan digit satuan dan digit puluhan.
6. Menambahkan node baru ke linked list hasil.
7. Jika setelah seluruh proses masih terdapat `carry`, maka membuat satu node tambahan.

---

## 📚 Konsep yang Dipelajari

- Singly Linked List
- Pointer
- Dynamic Memory Allocation (`new`)
- Traversal Linked List
- Head dan Tail Pointer
- Penanganan Carry
- Edge Case pada Linked List
- Manipulasi String (`to_string`, `stoi`, dan `erase`)

---

## 🤔 Hal yang Dipelajari Selama Pengerjaan

Selama mengerjakan soal ini saya memperoleh beberapa pemahaman baru mengenai linked list, di antaranya:

- Cara membangun linked list baru menggunakan pointer `head` dan `tail`.
- Perbedaan fungsi pointer dengan node yang ditunjuk.
- Cara melakukan traversal menggunakan `next`.
- Pentingnya menangani kondisi ketika salah satu linked list telah mencapai `nullptr`.
- Pentingnya membuat node baru apabila masih terdapat nilai `carry` setelah seluruh proses penjumlahan selesai.
- Cara menangani linked list dengan panjang yang berbeda.

---

## ⏱ Kompleksitas

| Jenis | Kompleksitas |
|-------|--------------|
| Waktu | **O(max(n, m))** |
| Ruang Tambahan | **O(max(n, m))** |

Keterangan:

- `n` = panjang linked list pertama.
- `m` = panjang linked list kedua.

---

## 🛠 Bahasa Pemrograman

- C++

---

## 🎯 Hasil

- ✅ Accepted
- Runtime : **6 ms**
- Time Complexity : **O(max(n, m))**

---

## 📌 Catatan

Solusi ini merupakan implementasi awal yang berhasil memperoleh status **Accepted**. Pada implementasi ini, proses pengelolaan nilai `carry` masih menggunakan manipulasi `string` (`to_string`, `stoi`, dan `erase`). Pendekatan tersebut memudahkan proses pengembangan dan debugging, namun masih dapat dioptimalkan pada versi berikutnya agar kode menjadi lebih sederhana dan efisien.