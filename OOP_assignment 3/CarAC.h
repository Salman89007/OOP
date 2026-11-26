#ifndef CARAC_H
#define CARAC_H
#include "vehicle.h"

class CarAC : public Vehicle {
public:
    CarAC() : Vehicle(120, 42, 250) {}
    double calculateFare(double km) const {
        double fare = Vehicle::calculateFare(km) * 1.4;
        if (fare < 400) return 400;
        return fare;
    }
    std::string getTag() const { return "CAR_AC"; }
};
#endif