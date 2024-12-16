#include <iostream>
#include "account.h"
#include "menu.h"

using namespace std;

// Menu utama
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
                cout << "Terima skibidi." << endl;
            break;
            default:
                cout << "Opsi tidak sigma. Coba lagi." << endl;
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}
