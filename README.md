# Image Converter — Grayscale to PGM

## 1. Deskripsi Proyek

Image Converter merupakan program sederhana untuk mengonversi gambar berformat JPG atau JPEG menjadi citra grayscale berformat PGM (Portable GrayMap).

Program ini dibuat menggunakan bahasa C++ dengan bantuan library `stb_image.h` dan `stb_image_write.h`.

Hasil konversi dapat digunakan sebagai gambar input pada proyek pengolahan citra, salah satunya **Sobel Edge Detection — Parallel Programming**.

## 2. Fungsi Program

Program ini memiliki fungsi utama:

- Membaca gambar dengan format JPG atau JPEG.
- Mengubah gambar berwarna menjadi grayscale.
- Menyimpan hasil konversi dalam format PGM (P5).
- Menghasilkan file gambar yang dapat digunakan sebagai input program Sobel Edge Detection.

## 3. Struktur Folder

```text
image_converter/
├── input/
│   └── foto1.jpg
├── output/
├── lib/
│   ├── stb_image.h
│   └── stb_image_write.h
├── convert.cpp
└── Makefile
```

Keterangan:

- `input/` berisi gambar asli yang akan dikonversi.
- `output/` merupakan lokasi penyimpanan hasil konversi.
- `lib/` berisi library untuk membaca dan menulis file gambar.
- `convert.cpp` merupakan source code proses konversi gambar.
- `Makefile` digunakan untuk mengotomatisasi proses kompilasi.

## 4. Persyaratan Sistem

Perangkat lunak yang dibutuhkan:

- Windows
- MSYS2 UCRT64
- GCC / G++
- GNU Make

## 5. Cara Kompilasi

Buka terminal **MSYS2 UCRT64** pada folder `image_converter`, kemudian jalankan:

```bash
make
```

Perintah tersebut akan mengompilasi program Image Converter berdasarkan konfigurasi pada Makefile.

Untuk menghapus file hasil kompilasi:

```bash
make clean
```

## 6. Cara Menjalankan Program

1. Siapkan gambar JPG atau JPEG yang akan dikonversi.
2. Masukkan gambar ke dalam folder `input/`.
3. Pastikan nama file sesuai dengan nama yang digunakan pada source code.
4. Jalankan program:

```bash
./convert.exe
```

## 7. Hasil Konversi

Hasil konversi akan disimpan secara otomatis pada folder `output/` dalam format PGM (P5).

File hasil konversi dapat digunakan sebagai input untuk program Sobel Edge Detection.

## 8. Penggunaan pada Proyek Sobel Edge Detection

Jika belum memiliki gambar grayscale berformat PGM, program ini dapat digunakan sebagai tahap persiapan sebelum menjalankan Sobel Edge Detection.

Langkah-langkah:

1. Jalankan Image Converter untuk mengonversi gambar JPG atau JPEG.
2. Ambil hasil konversi dari folder `output/`.
3. Salin file PGM ke folder `input/` pada repository Sobel Edge Detection.
4. Sesuaikan nama file menjadi `foto1.pgm` jika diperlukan.
5. Jalankan program Sobel Edge Detection sesuai petunjuk pada README repository tersebut.

**Repository Sobel Edge Detection:** [Sobel Edge Detection — GitHub](https://github.com/azhar2301/paralel-2322105075-Muhammad-Azhar)