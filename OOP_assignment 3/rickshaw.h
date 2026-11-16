#ifndef RICKSHAW_H
#define RICKSHAW_H

#include <string>
#include "Vehicle.h"

class Rickshaw : public Vehicle
{
public:
    Rickshaw() : Vehicle(70, 24, 120) {}
    std::string getTag() const override { return "RICKSHAW"; }
};

#endif