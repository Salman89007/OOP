#ifndef CAR_ECONOMY_H
#define CAR_ECONOMY_H

#include <string>
#include "Vehicle.h"

class CarEconomy : public Vehicle
{
public:
    CarEconomy() : Vehicle(120, 42, 250) {}
    std::string getTag() const override { return "CAR_ECONOMY"; }
};

#endif