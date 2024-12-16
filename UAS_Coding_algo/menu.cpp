//
// Created by USER on 16/12/2024.
//

#include "menu.h"
#include "menu.h"
#include <iostream>
using namespace std;

// Menu pembeli
void buyerMenu(const string& username) {
    int choice;
    do {
        cout << "\n=== Menu Pembeli ===" << endl;
        cout << "1. Lihat Produk" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "[" << username << "] Melihat produk..." << endl;
            break;
            case 2:
                cout << "[" << username << "] Membuat pesanan..." << endl;
            break;
            case 0:
                cout << "Logout berhasil." << endl;
            break;
            default:
                cout << "Opsi tidak valid. Coba lagi." << endl;
        }
    } while (choice != 0);
}

// Menu penjual
void sellerMenu(const string& username) {
    int choice;
    do {
        cout << "\n=== Menu Penjual ===" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Lihat Pesanan" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "[" << username << "] Menambah produk..." << endl;
            break;
            case 2:
                cout << "[" << username << "] Melihat pesanan..." << endl;
            break;
            case 0:
                cout << "Logout berhasil." << endl;
            break;
            default:
                cout << "Opsi tidak valid. Coba lagi." << endl;
        }
    } while (choice != 0);
}
