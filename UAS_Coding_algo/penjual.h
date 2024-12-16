#ifndef PENJUAL_H
#define PENJUAL_H

#include <string>
#include <vector>
using namespace std;

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

// Fungsi untuk menambah menu
void tambahMenu(vector<Menu>& menuItems);

// Fungsi untuk membuat akun penjual
void buatAkunPenjual();

#endif


