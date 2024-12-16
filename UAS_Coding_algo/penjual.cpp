#include "penjual.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Bagian Akun Penjual, James Edison Wihardja, 2410101041

struct Menu {
    string nama;
    double harga;
    string linkFoto;
};

struct AkunPenjual {
    string gmail;
    string whatsappBusiness;
    string metodePembayaran;
    string namaGerobak;
    string jamOperasional;
    string lokasi;
    vector<Menu> menuItems;
    bool gpsAccess;
    bool layananAntar;
    double jarakMinimum;
    double jarakMaksimum;
    double biayaOngkos;
};

void tambahMenu(vector<Menu> &menuItems) {
    string nama, linkFoto;
    double harga;
    while (true) {
        cout << "\n" << "Nama menu makanan / minuman: ";
        cin.ignore();
        getline(cin, nama);
        
        cout << "Harga menu (Rp): ";
        cin >> harga;
        
        cout << "Link photo menu makanan / minuman: ";
        cin.ignore();
        getline(cin, linkFoto);

        Menu menuItem;
        menuItem.nama = nama;
        menuItem.harga = harga;
        menuItem.linkFoto = linkFoto;
        menuItems.push_back(menuItem);

        char pilihan;
        cout << "\n" << "tambah menu item? (y/n): ";
        cin >> pilihan;
        if (pilihan == 'n' || pilihan == 'N') {
            break;
        }
    }
}

void buatAkunPenjual() {
    AkunPenjual accPenjual;
 
    cout << "Masukkan Gmail Anda: ";
    cin >> accPenjual.gmail;

    do {
        cout << "Input nomor WhatsApp Business" << "\n" <<  
        "(Input belum jika tidak punya nomor WhatsApp Business): ";
        
        cin >> accPenjual.whatsappBusiness;
        
        if (accPenjual.whatsappBusiness == "belum") {
            cout << "\n" << "Buatlah nomor WhatsApp Business terlebih dahulu!!." << "\n";
        }
    } while(accPenjual.whatsappBusiness == "belum");

    cout << "Metode pembayaran: ";
    cin.ignore();
    getline(cin, accPenjual.metodePembayaran);
    cout << "Nama Gerobak: ";
    getline(cin, accPenjual.namaGerobak);
    cout << "Jam Operasi: ";
    getline(cin, accPenjual.jamOperasional);
    cout << "Lokasi Operasi: ";
    getline(cin, accPenjual.lokasi);

    tambahMenu(accPenjual.menuItems);

    string fotoGerobak;
    cout << "Foto Gerobak (dalam bentuk link): ";
    cin.ignore();
    getline(cin, fotoGerobak);
    
    cout << "\n" << accPenjual.namaGerobak << "\n";
    for (int i = 0; i < accPenjual.menuItems.size(); ++i) {
        cout << "Menu: " << accPenjual.menuItems[i].nama << " | "<< "Harga: " << accPenjual.menuItems[i].harga << " | " << "Link Foto: " << accPenjual.menuItems[i].linkFoto << endl;
    }

    do {
        cout << "\n" << "Izinkan akses GPS? (y/n): ";
        char gpsAccess;
        cin >> gpsAccess;
        
        accPenjual.gpsAccess = (gpsAccess == 'y' || gpsAccess == 'Y');
        if (!accPenjual.gpsAccess) {
            cout << "Akses GPS diperlukan untuk melakukan operasi aplikasi." << "\n";
        }
    } while (!accPenjual.gpsAccess);

    cout << "Apakah anda memberikan layanan antar makan? (y/n): ";
    char antar;
    cin >> antar;
    
    accPenjual.layananAntar = (antar == 'y' || antar == 'Y');
    
    if (accPenjual.layananAntar) {
        cout << "Input jarak minimum antar makan (km): ";
        cin >> accPenjual.jarakMinimum;
        cout << "Input jarak maksimum antar makan (km): ";
        cin >> accPenjual.jarakMaksimum;
        cout << "Input ongkos antar makan (Rp): ";
        cin >> accPenjual.biayaOngkos;
        cout << "\n" << "PENGIRIMAN DITAWARKAN ATAS RESIKO ANDA SENDIRI & TIDAK DIDUKUNG OLEH PIHAK APLIKASI!!" << "\n";
    }

    cout << "\n" << "Akun penjual telah dibuat!" << "\n";
    cout << "Gmail: " << accPenjual.gmail << "\n";
    cout << "WhatsApp Business: " << accPenjual.whatsappBusiness << "\n";
    cout << "Payment Method: " << accPenjual.metodePembayaran << "\n";
    cout << "Nama Gerobak: " << accPenjual.namaGerobak << "\n";
    cout << "Jam Operasional: " << accPenjual.jamOperasional << "\n";
    cout << "Lokasi: " << accPenjual.lokasi << "\n";

    cout << "\n" << "Menu Makanan & Minuman:" << "\n";
    for (int i = 0; i < accPenjual.menuItems.size(); ++i) {
        cout << "- " << accPenjual.menuItems[i].nama << " (Rp" << accPenjual.menuItems[i].harga << "): " << accPenjual.menuItems[i].linkFoto << "\n";
    }

    if (accPenjual.layananAntar) {
        cout << "\n" << "Jasa antar makan:" << "\n";
        cout << "Jarak Minimum: " << accPenjual.jarakMinimum << " km" << "\n";
        cout << "Jarak Maksimum: " << accPenjual.jarakMaksimum << " km" << "\n";
        cout << "Biaya ongkos antar makan: Rp" << accPenjual.biayaOngkos << "\n";
    }
}


