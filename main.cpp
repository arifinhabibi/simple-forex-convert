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


#include <iostream>
#include <iomanip>
using namespace std;

string formatAngka(double angka);

int main() {
    int jumlahDollar;
    double kursUSD, kursSGD;

    cout << "Masukkan kurs USD ke IDR: ";
    cin >> kursUSD;

    cout << "Masukkan kurs SGD ke IDR: ";
    cin >> kursSGD;

    cout << "\nTabel Konversi Mata Uang\n\n";

    cout << left
         << setw(15) << "USD"
         << setw(20) << "IDR"
         << setw(20) << "SGD"
         << "IDR" << endl;

    cout << "---------------------------------------------------------------\n";

    for (jumlahDollar = 1; jumlahDollar <= 10; jumlahDollar++) {
        cout << left
             << setw(15) << jumlahDollar
             << setw(20) << formatAngka(jumlahDollar * kursUSD)
             << setw(20) << jumlahDollar
             << formatAngka(jumlahDollar * kursSGD)
             << endl;
    }

    return 0;
}



// function untuk memformat angka dengan pemisah ribuan dan dua desimal
string formatAngka(double angka) {
    stringstream stream;
    stream << fixed << setprecision(2) << angka;

    string hasil = stream.str();
    size_t posisiDesimal = hasil.find('.');

    string bagianBulat = hasil.substr(0, posisiDesimal);
    string bagianDesimal = hasil.substr(posisiDesimal);

    for (int posisi = static_cast<int>(bagianBulat.length()) - 3;
         posisi > 0; posisi -= 3) {
        bagianBulat.insert(posisi, ",");
    }

    return bagianBulat + bagianDesimal;
}


