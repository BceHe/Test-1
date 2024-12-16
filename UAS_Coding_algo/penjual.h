#ifndef PENJUAL_H
#define PENJUAL_H

#include <string>
#include <vector>
using namespace std;

struct Menu {
    std::string nama;
    double harga;
    std::string linkFoto;
};

struct AkunPenjual {
    std::string gmail;
    std::string whatsappBusiness;
    std::string metodePembayaran;
    std::string namaGerobak;
    std::string jamOperasional;
    std::string lokasi;
    std::vector<Menu> menuItems;
    bool gpsAccess;
    bool layananAntar;
    double jarakMinimum;
    double jarakMaksimum;
    double biayaOngkos;
};

// Fungsi untuk menambah menu
void tambahMenu(std::vector<Menu>& menuItems);

// Fungsi untuk membuat akun penjual
void buatAkunPenjual();

#endif


