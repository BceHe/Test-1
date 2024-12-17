#include <iostream>
#include <vector>
#include <cmath>
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



void sellerMenu(string loggedInUser) {
    cout << "Menu Penjual (" << loggedInUser << ")" << endl;

    char activateGPS;
    cout << "Apakah Anda ingin mengaktifkan GPS? (y/n): ";
    cin >> activateGPS;
    if (activateGPS == 'y' || activateGPS == 'Y') {
        activateGPSForPenjual(loggedInUser);
    }

    char receiveOrder;
    cout << "Apakah Anda menerima pesanan baru? (y/n): ";
    cin >> receiveOrder;
    if (receiveOrder == 'y' || receiveOrder == 'Y') {
       cout << "Pesanan yang diterima:\n";
        for (const auto &order : orders) {
            cout << "Pembeli: " << order.buyerName << "\n";
            cout << "Daftar menu yang dipesan:\n";
            for (const auto &menu : order.menuItems) {
                cout << "- " << menu.nama << " | Rp" << menu.harga << " | " << menu.linkFoto << "\n";
            }
        }
    
        cout << "Menghubungi pembeli via WhatsApp untuk konfirmasi lebih lanjut..." << endl;

        double distanceToBuyer;
        cout << "Masukkan jarak Anda ke pembeli dalam meter: ";
        cin >> distanceToBuyer;
        if (distanceToBuyer <= 100) {
            cout << "Pembeli sudah dekat. Order dapat diselesaikan." << endl;
        } else {
            cout << "Pembeli belum cukup dekat. Menunggu konfirmasi." << endl;
        }

        char cancelOrder;
        cout << "Apakah pembeli membatalkan pesanan? (y/n): ";
        cin >> cancelOrder;
        if (cancelOrder == 'y' || cancelOrder == 'Y') {
            cout << "Pesanan dibatalkan. Anda tetap akan menerima pembayaran." << endl;
        }
    }
}

