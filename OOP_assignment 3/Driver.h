#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "User.h"

class Driver : public User {
protected:
    std::string vehicleTag;

public:
    static int liveCount;

    Driver(std::string id, std::string name, std::string number, std::string pin,
           double walletBalance, double ratingTotal, int ratingCount,
           std::string vehicleTag);
    void showMenu();
    ~Driver();
};

#endif