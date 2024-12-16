#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "account.h"
#include "menu.h"
#include "penjual.h"
#include "pembeli.h"

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

void buyerMenu(string loggedInUser) {
    cout << "Menu Pembeli (" << loggedInUser << ")" << endl;
    
    cout << "Mendeteksi Penjual terdekat..." << endl;
    Location penjualLocation = { -6.2088, 106.8456 };
    Location pembeliLocation = { -6.1990, 106.8355 };

    double distance = calculateDistance(penjualLocation, pembeliLocation);
    if (distance <= 5.0) {
        cout << "Penjual terdekat dalam radius 5 km ditemukan." << endl;
        cout << "Jarak: " << distance << " km" << endl;
        
        vector<string> menuItems = { "Nasi Goreng", "Mie Goreng", "Es Teh" };
        int orderChoice;
        cout << "Pilih menu untuk dipesan (masukkan nomor):" << endl;
        for (int i = 0; i < menuItems.size(); ++i) {
            cout << i + 1 << ". " << menuItems[i] << endl;
        }
        cout << "Pilihan: ";
        cin >> orderChoice;

        if (orderChoice > 0 && orderChoice <= menuItems.size()) {
            cout << "Menu yang Anda pilih: " << menuItems[orderChoice - 1] << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }

        char confirmOrder;
        cout << "Konfirmasi pesanan? (y/n): ";
        cin >> confirmOrder;
        if (confirmOrder == 'y' || confirmOrder == 'Y') {
            cout << "Pesanan telah dikonfirmasi. Silakan lakukan pembayaran secara online." << endl;
        }
    } else {
        cout << "Penjual terlalu jauh. Jarak: " << distance << " km" << endl;
    }
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
        cout << "Pesanan diterima. Anda dapat memulai memasak." << endl;
    
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
                    sellerMenu(loggedInUser);
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

