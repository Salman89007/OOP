#ifndef CAR_ECONOMY_H
#define CAR_ECONOMY_H

#include <string>
#include "Vehicle.h"

class CarEconomy : public Vehicle
{
public:
    CarEconomy() : Vehicle(50, 18, 80) {}
    std::string getTag() const override { return "CARECONOMY"; }
};

#endif