
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"

using namespace std;
namespace fs = std::filesystem;

int main() {

    // =====================================
    // NAMA FILE GAMBAR INPUT
    // =====================================

    string inputFile = "input/me_with_abil.jpg";

    // =====================================
    // MEMBACA GAMBAR
    // =====================================

    int width, height, channels;

    unsigned char* img = stbi_load(
        inputFile.c_str(),
        &width,
        &height,
        &channels,
        0
    );

    if (img == nullptr) {
        cerr << "Gagal membaca gambar!\n";
        cerr << "Periksa nama dan lokasi file.\n";
        return 1;
    }

    cout << "Gambar berhasil dibaca!\n";
    cout << "Lebar  : " << width << " pixel\n";
    cout << "Tinggi : " << height << " pixel\n";

    // =====================================
    // KONVERSI KE GRAYSCALE
    // =====================================

    unsigned char* gray = new unsigned char[width * height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int index = (y * width + x) * channels;

            unsigned char r = img[index];
            unsigned char g = img[index + 1];
            unsigned char b = img[index + 2];

            int grayValue =
                (int)(0.299 * r +
                      0.587 * g +
                      0.114 * b);

            gray[y * width + x] =
                static_cast<unsigned char>(grayValue);
        }
    }

    // =====================================
    // MENENTUKAN NAMA OUTPUT
    // =====================================

    fs::path inputPath(inputFile);

    string outputName =
        inputPath.stem().string() + ".pgm";

    string outputFile =
        "output/" + outputName;

    // =====================================
    // MENYIMPAN FORMAT PGM
    // =====================================

    int success = stbi_write_png(
        outputFile.c_str(),
        width,
        height,
        1,
        gray,
        width
    );

    // Catatan:
    // Bagian penyimpanan PGM menggunakan
    // fungsi khusus di bawah ini.

    if (success) {
        cout << "Konversi berhasil!\n";
    }

    // Simpan PGM menggunakan format P5
    FILE* file = fopen(outputFile.c_str(), "wb");

    if (file == nullptr) {
        cerr << "Gagal membuat file output!\n";
        delete[] gray;
        stbi_image_free(img);
        return 1;
    }

    fprintf(file, "P5\n%d %d\n255\n", width, height);

    fwrite(gray, sizeof(unsigned char),
           width * height, file);

    fclose(file);

    cout << "File output : " << outputFile << "\n";
    cout << "Format      : PGM (P5)\n";

    // =====================================
    // MEMBERSIHKAN MEMORI
    // =====================================

    delete[] gray;
    stbi_image_free(img);

    cout << "\nProgram selesai.\n";

    return 0;
}
