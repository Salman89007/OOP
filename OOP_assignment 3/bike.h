#ifndef BIKE_H
#define BIKE_H

#include <string>
#include "Vehicle.h"

class Bike : public Vehicle
{
public:
    Bike() : Vehicle(50, 18, 80) {}
    std::string getTag() const override { return "BIKE"; }
};

#endif