#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "account.h"
#include "menu.h"
#include "penjual.h"
#include "pembeli.h"
#include "buyer.h"
#include "seller.h"

using namespace std;

struct Location {
    double latitude;
    double longitude;
};

void activateGPSForPenjual(string loggedInUser) {
    double latitude, longitude;
    cout << "Masukkan latitude untuk lokasi Anda (penjual): ";
    cin >> latitude;
    cout << "Masukkan longitude untuk lokasi Anda (penjual): ";
    cin >> longitude;

    cout << "GPS lokasi aktif. Lokasi Penjual (" << latitude << ", " << longitude << ")" << endl;
}

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

void mainMenu() {
    int choice;
    do {
        cout << "\n=== Sistem Login ===" << endl;
        cout << "1. Buat Akun Pembeli" << endl;
        cout << "2. Buat Akun Penjual" << endl;
        cout << "3. Login sebagai Pembeli" << endl;
        cout << "4. Login sebagai Penjual" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        string loggedInUser;

        switch (choice) {
            case 1:
                createAccount("Pembeli");
                break;
            case 2:
                createAccount("Penjual");
                break;
            case 3:
                if (login("Pembeli", loggedInUser)) {
                    buyerMenu(loggedInUser);
                }
                break;
            case 4:
                if (login("Penjual", loggedInUser)) {
                    buatAkunPenjual();
                }
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem kami." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Coba lagi." << endl;
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}

