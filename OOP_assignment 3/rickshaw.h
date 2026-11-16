#ifndef RICKSHAW_H
#define RICKSHAW_H

#include <string>
#include "Vehicle.h"

class Rickshaw : public Vehicle
{
public:
    Rickshaw() : Vehicle(50, 18, 80) {}
    std::string getTag() const override { return "RICKSHAW"; }
};

#endif