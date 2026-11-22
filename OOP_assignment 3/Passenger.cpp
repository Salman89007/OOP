#include "Passenger.h"
#include<iostream>
int Passenger::liveCount = 0;
Passenger::Passenger(std::string id, std::string name, std::string number, std::string pin,
                     double walletBalance, double ratingTotal, int ratingCount)
    : User(id, name, number, pin, walletBalance, ratingTotal, ratingCount) {
    liveCount++;
}
void Passenger::showMenu() {
    std::cout << "1. Post ride request\n"
              << "2. View offers\n"
              << "3. Top up wallet\n"
              << "4. View wallet\n"
              << "0. Logout\n";
}
Passenger::~Passenger(){
    liveCount--;
}
