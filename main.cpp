/*

Algoritma
Algoritma KonversiMataUang

DEKLARASI:
    jumlahDollar : integer
    kursUSD : real
    kursSGD : real

DESKRIPSI:
    OUTPUT "Masukkan kurs USD ke IDR: "
    INPUT kursUSD

    OUTPUT "Masukkan kurs SGD ke IDR: "
    INPUT kursSGD

    OUTPUT "Tabel Konversi Mata Uang"

    FOR jumlahDollar = 1 TO 10 DO
        OUTPUT jumlahDollar,
               jumlahDollar * kursUSD,
               jumlahDollar,
               jumlahDollar * kursSGD
    END FOR

SELESAI

*/ 

/*

Bahasa pemrograman C++ mewajibkan setiap aplikasi memiliki satu fungsi utama 
bernama (int main()) sebagai gerbang masuk tunggal yang berjalan dari atas ke bawah,
di mana kata int berfungsi untuk melaporkan status sukses 
program berupa angka bulat (return 0;) ke sistem operasi [Dicoding Blog].
Dalam struktur dasarnya, C++ memisahkan tipe data dasar seperti int atau double
yang bisa langsung ditulis, dengan tipe data objek atau fitur bawaan pustaka standar 
seperti (std::string), (std::cin), dan (std::cout) yang wajib ditulis dengan awalan (std::) 
jika kamu tidak mendeklarasikan perintah (using namespace std) di awal kode [Dicoding Blog].

*/ 

// iostream berguna untuk memanggil function cin, endl atau cout
#include <iostream>

// iomanip berguna untuk memanggi function left atau setw
#include <iomanip>

// string menjadi sebuah parent dalam konsep oop
#include <string>

// sstream memanggil function stream
#include <sstream>

// bentuk deklarasi function
std::string formatAngka(double angka);

// function utama dalam cpp itu bernama main
int main() {
    // deklarasi variabel
    int jumlahDollar;
    double kursUSD, kursSGD;

    std::cout << "Masukkan kurs USD ke IDR: ";
    std::cin >> kursUSD;

    std::cout << "Masukkan kurs SGD ke IDR: ";
    std::cin >> kursSGD;

    std::cout << "\nTabel Konversi Mata Uang\n\n";

    std::cout << std::left
         << std::setw(15) << "USD"
         << std::setw(20) << "IDR"
         << std::setw(20) << "SGD"
         << "IDR" << std::endl;

    std::cout << "---------------------------------------------------------------\n";

    // looping untuk menampilkan tabel konversi mata uang
    for (jumlahDollar = 1; jumlahDollar <= 10; jumlahDollar++) {
        std::cout << std::left
             << std::setw(15) << jumlahDollar
             << std::setw(20) << formatAngka(jumlahDollar * kursUSD)
             << std::setw(20) << jumlahDollar
             << formatAngka(jumlahDollar * kursSGD)
             << std::endl;
    }

    return 0;
}



// Function untuk memformat angka dengan koma sebagai pemisah ribuan
std::string formatAngka(double angka) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << angka;

    std::string hasil = stream.str();
    size_t posisiDesimal = hasil.find('.');

    std::string bagianBulat = hasil.substr(0, posisiDesimal);
    std::string bagianDesimal = hasil.substr(posisiDesimal);

    for (int posisi = static_cast<int>(bagianBulat.length()) - 3;
         posisi > 0; posisi -= 3) {
        bagianBulat.insert(posisi, ",");
    }

    return bagianBulat + bagianDesimal;
}


