#include <iostream>
#include <vector>
#include <cmath>
#include "penjual.h"
using namespace std;


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

