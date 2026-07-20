# Notes

## Yang saya pelajari

- push_back() dapat menambah ukuran vector.
- size() berubah setelah push_back().
- Simpan ukuran awal sebelum looping.

## Kesalahan pertama

Saya mencoba

```cpp
final[i] = nums[i];
```

padahal vector masih kosong.

## Kesalahan kedua

Saya membuat

```cpp
vector<int> nums;
```

padahal parameter sudah bernama nums.

## Ide awal

Awalnya saya ingin membuat vector baru (`ans`), tetapi saya sadar `push_back()` bisa langsung memperbesar `nums`.

Karena soal tidak melarang mengubah input, saya memilih solusi tersebut.

## Hal yang ingin dipelajari

- reserve()
- resize()
- emplace_back()