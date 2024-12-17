#include <iostream>
#include <vector>
#include <cmath>
#include "pembeli.h"
#include "penjual.h"
using namespace std;

double calculateDistance(Location loc1, Location loc2) {
    const double R = 6371;
    double lat1 = loc1.latitude * M_PI / 180;
    double lon1 = loc1.longitude * M_PI / 180;
    double lat2 = loc2.latitude * M_PI / 180;
    double lon2 = loc2.longitude * M_PI / 180;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

void buyerMenu(string loggedInUser) {
    cout << "Menu Pembeli (" << loggedInUser << ")" << endl;
    
    cout << "Mendeteksi Penjual terdekat..." << endl;
    Location penjualLocation = { -6.2088, 106.8456 };
    Location pembeliLocation = { -6.1990, 106.8355 };

    double distance = calculateDistance(penjualLocation, pembeliLocation);
    if (distance <= 5.0) {
        cout << "Penjual terdekat dalam radius 5 km ditemukan." << endl;
        cout << "Jarak: " << distance << " km" << endl;

        if (menuItems.empty()) {
        cout << "Menu tidak tersedia saat ini." << endl;
        return;
    }
        
       cout << "Daftar Menu:" << endl;
    for (const auto &menu : menuItems) {
        cout << "- " << menu.nama << " | Rp" << menu.harga << " | " << menu.linkFoto << endl;
    }

    string menuChoice;
    cout << "berikut adalah menu yang bisa anda pilih: " << menuItems << endl;
    cin >> menuChoice;
    getline(cin, menuChoice);

    bool found = false;
    for (const auto &menu : menuItems) {
        if (menu.nama == menuChoice) {
            found = true;
            cout << "\nMenu yang Anda pilih: " << menu.nama << endl;
            cout << "Harga: Rp" << menu.harga << endl;

            char confirmOrder;
            cout << "Konfirmasi pesanan? (y/n): ";
            cin >> confirmOrder;
            if (confirmOrder == 'y' || confirmOrder == 'Y') {
                cout << "Pesanan telah dikonfirmasi. Silakan lakukan pembayaran secara online." << endl;
                Order newOrder;
                newOrder.buyerName = loggedInUser;
                newOrder.menuItem = menu;
                orders.push_back(newOrder);
            }
            break;
        }
    } else {
        cout << "anda belum ada di dekat penjual, perbedaan Jarak: " << distance << " km" << endl;
    }
}
