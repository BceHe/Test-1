//
// Created by USER on 16/12/2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

struct Account {
    string username;
    string password;
    string whatsapp;
    string gmail;
};

void createAccount(const string& userType);
bool login(const string& userType, string& loggedInUser);

#endif





