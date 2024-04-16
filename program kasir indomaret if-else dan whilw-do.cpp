#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string lanjut_belanja;

    cout << "=========================================\n";
    cout << "C++ Program Pembayaran di Kasir Indomaret\n";
    cout << "=========================================\n\n";

    do {
        // inisialisasi variable terlebih dahulu.
        int jumlah_beli, bayar, diskon, jumlah[100], harga[100], total[50];
        float total_semua = 0;
        string nama_barang[100];

        cout << "Masukan jumlah barang yang dibeli :\t";
        cin >> jumlah_beli;

        cin.ignore(); //pembeli dan jumlah barang yang di beli.

        for (int i = 0; i < jumlah_beli; i++) {
            cout << "\nMasukan Barang ke- " << i + 1 << "\n";
            cout << "Nama Barang\t\t: ";
            getline(cin, nama_barang[i]); //input nama barang yang dibeli

            cout << "Jumlah Barang\t: ";
            cin >> jumlah[i];
            // Validasi input jumlah barang
            while (jumlah[i] <= 0) {
                cout << "Jumlah barang harus lebih besar dari 0. Silakan coba lagi.\n";
                cout << "Jumlah Barang\t: ";
                cin >> jumlah[i];
            }

            cout << "Harga Barang\t: Rp.";
            cin >> harga[i] ;
            
            // Validasi input harga barang
            while (harga[i] <= 0) {
                cout << "Harga barang harus lebih besar dari 0. Silakan coba lagi.\n";
                cout << "Harga Barang\t: Rp.";
                cin >> harga[i];
            }

            total[i] = jumlah[i] * harga[i]; //jumlah harga total barang
            total_semua += total[i]; // menjumlahkan seluruh total barang

            cin.ignore(); // untuk membersihkan newline yang tersisa di buffer
        }

        cout << "\n==================================================";
        cout << "\n========Catatan Belanja Customer Indomaret========";
        cout << "\n==================================================";

        cout << "\n\nNo  Nama Barang\t\tJumlah\t\tHarga\t\tTotal\n";
        for (int i = 0; i < jumlah_beli; i++) {
            cout << i + 1 << setw(12) << nama_barang[i] << setw(10) << jumlah[i] << setw(10) << "Rp." << harga[i] << setw(9) << "Rp." << total[i] << endl;
        }

        //percabangan kondisi diskon
        if (total_semua >= 100000) {
            diskon = 0.06 * total_semua;
        } else if (total_semua >= 50000) {
            diskon = 0.04 * total_semua;
        } else if (total_semua >= 25000) {
            diskon = 0.02 * total_semua;
        } else {
            diskon = 0;
        }

        cout << "\n\nJumlah Bayar: Rp." << total_semua << endl;
        cout << "Diskon\t\t: Rp." << diskon << endl;
        cout << "Total Bayar\t: Rp." << total_semua - diskon << endl;

        // Validasi input jumlah bayar
        do {
            cout << "Bayar\t\t: Rp.";
            cin >> bayar;
            if (bayar < total_semua - diskon) {
                cout << "Jumlah bayar harus lebih besar atau sama dengan total belanja setelah diskon. Silakan coba lagi.\n";
            }
        } while (bayar < total_semua - diskon);

        cout << "Kembalian\t: Rp." << (bayar - (total_semua - diskon)) << ",00" << endl;

        cout << "\nApakah Anda ingin melanjutkan belanja? (ya/tidak): ";
        cin >> lanjut_belanja;
        cin.ignore(); // membersihkan newline di buffer
    } while (lanjut_belanja == "ya" || lanjut_belanja == "Ya");

    cout << "\n========Terimakasih telah berbelanja di Indomaret========";
    return 0;
}

