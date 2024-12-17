#include <iostream>
#include <vector>
#include <cmath>
#include "penjual.h"
#include "pembeli.h"
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



void sellerMenu(string loggedInUser) {
    cout << "Menu Penjual (" << loggedInUser << ")" << endl;

    char activateGPS;
    cout << "Apakah Anda ingin mengaktifkan GPS? (y/n): ";
    cin >> activateGPS;
    if (activateGPS == 'y' || activateGPS == 'Y') {
        activateGPSForPenjual(loggedInUser);
    }

    if (orders.empty()) {
        cout << "Tidak ada pesanan saat ini." << endl;
        return;
    }
    
    char receiveOrder;
    cout << "Apakah Anda menerima pesanan baru? (y/n): ";
    cin >> receiveOrder;
    if (receiveOrder == 'y') {
     cout << "Daftar Pesanan yang Diterima:" << endl;
        for (const auto &order : orders) {
            cout << "Pembeli: " << order.buyerName << endl;
            cout << "- Menu: " << order.menuItem.nama << endl;
            cout << "  Harga: Rp" << order.menuItem.harga << endl;
            cout << "  Link Foto: " << order.menuItem.linkFoto << endl;
            }else {
            cout << "pesanan di tolak oleh penjual." << endl;
        }
        double distanceToBuyer;
        cout << "Masukkan jarak Anda ke pembeli dalam meter: ";
        cin >> distanceToBuyer;
        if (distanceToBuyer <= 100) {
            cout << "Pembeli sudah dekat. Order dapat diselesaikan." << endl;
        } else {
            cout << "Pembeli belum cukup dekat. Menunggu konfirmasi." << endl;
        }
         char completeOrder;
        cout << "Apakah pembeli sudah mengambil makanan? (y/n): ";
        cin >> completeOrder;
        if (completeOrder == 'y' || completeOrder == 'Y') {
            cout << "Pesanan telah selesai dan diambil oleh pembeli." << endl;
            orders.erase(orders.begin());
        } else {
            cout << "Pesanan belum selesai. Menunggu pembeli mengambil makanan." << endl;
        }
    }
}

