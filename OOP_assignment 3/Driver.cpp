#include <iostream>
#include "Driver.h"

int Driver::liveCount = 0;

Driver::Driver(std::string id, std::string name, std::string number, std::string pin,
               double walletBalance, double ratingTotal, int ratingCount,
               std::string vehicleTag)
    : User(id, name, number, pin, walletBalance, ratingTotal, ratingCount),
      vehicleTag(vehicleTag) {
    liveCount++;
}

Driver::~Driver() {
    liveCount--;
}

void Driver::showMenu() {
    std::cout << "1. View open requests\n"
              << "2. Make offer / counter\n"
              << "3. Complete trip\n"
              << "4. View wallet\n"
              << "0. Logout\n";
}