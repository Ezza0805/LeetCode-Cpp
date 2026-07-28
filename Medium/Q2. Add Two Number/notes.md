# Notes

## Yang saya pelajari

- Cara membuat dan menghubungkan node pada singly linked list.
- Perbedaan fungsi `head` dan `tail`.
- Pointer dapat dipindahkan tanpa mengubah isi linked list.
- `nullptr` digunakan untuk menandakan bahwa pointer tidak menunjuk ke node mana pun.
- Cara melakukan traversal menggunakan `next`.
- Cara membangun linked list baru sebagai hasil operasi.
- Pentingnya menangani linked list dengan panjang yang berbeda.
- Pentingnya menangani `carry` setelah seluruh proses penjumlahan selesai.

---

## Kesalahan pertama

Awalnya saya hanya membuat satu pointer hasil.

```cpp
ListNode* hasil = nullptr;
```

Akibatnya saya kehilangan referensi ke node pertama ketika pointer hasil berpindah ke node berikutnya.

Saya kemudian memisahkan menjadi `hasilHead` dan `hasilTail`.

---

## Kesalahan kedua

Saya menggunakan

```cpp
while (l1 != nullptr && l2 != nullptr)
```

Akibatnya proses berhenti ketika salah satu linked list habis, padahal linked list lainnya masih memiliki node.

Saya menggantinya menjadi

```cpp
while (l1 != nullptr || l2 != nullptr)
```

agar seluruh node tetap diproses.

---

## Kesalahan ketiga

Saya langsung melakukan

```cpp
l1 = l1->next;
l2 = l2->next;
```

di setiap iterasi.

Padahal salah satu pointer bisa saja sudah `nullptr`, sehingga berpotensi menyebabkan program mengalami error.

Saya kemudian memindahkan perpindahan pointer ke dalam kondisi yang sesuai.

---

## Ide awal

Awalnya saya berpikir untuk menjumlahkan seluruh angka terlebih dahulu, kemudian mengubah hasilnya kembali menjadi linked list.

Namun setelah memahami cara kerja soal, saya menyadari bahwa penjumlahan dilakukan satu node demi satu node, sehingga lebih tepat membangun linked list hasil secara langsung selama proses traversal.

---

## Hal yang ingin dipelajari

- Cara mengelola `carry` tanpa menggunakan `string`.
- Cara membuat solusi dengan baris kode yang lebih singkat.
- Optimasi runtime dan penggunaan memori.
- Dummy Head Node.
- Smart Pointer (`std::unique_ptr`).
- Doubly Linked List.
- Circular Linked List.