// tes edit bisa gak ya di git
// Created by USER on 16/12/2024.
//

#include "account.h"
#include "account.h"
#include <iostream>
#include <fstream>
using namespace std;

// Fungsi untuk membuat akun
void createAccount(const string& userType) {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Simpan ke file
    string filename = (userType == "Pembeli") ? "buyers.txt" : "sellers.txt";
    ofstream file(filename, ios::app); // Menambahkan data baru
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Akun " << userType << " berhasil dibuat!" << endl;
    } else {
        cout << "Gagal menyimpan akun." << endl;
    }
}

// Fungsi untuk login
bool login(const string& userType, string& loggedInUser) {
    string username, password, fileUsername, filePassword;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Buka file sesuai userType
    string filename = (userType == "Pembeli") ? "buyers.txt" : "sellers.txt";
    ifstream file(filename);
    if (file.is_open()) {
        while (file >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                loggedInUser = username;
                cout << "Login berhasil sebagai " << userType << "!" << endl;
                return true;
            }
        }
        file.close();
    }
    cout << "Login gagal. Username atau password salah." << endl;
    return false;
}

