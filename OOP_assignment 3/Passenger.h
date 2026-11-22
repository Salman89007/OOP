#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"

class Passenger : public User{

public: 
Passenger(std::string id, std::string name, std::string number, std::string pin,
         double walletBalance, double ratingTotal, int ratingCount);
void showMenu();

static int liveCount;

~Passenger();
};

#endif