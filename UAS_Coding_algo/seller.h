#ifndef SELLER_H
#define SELLER_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Location {
    double latitude;
    double longitude;
};

double calculateDistance(Location loc1, Location loc2);
void sellerMenu(string loggedInUser);

#endif
