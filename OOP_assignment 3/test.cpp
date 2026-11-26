#include <iostream>
#include "vehicle.h"
#include "bike.h"
#include "rickshaw.h"
#include "CarEconomy.h"
#include "CarAC.h"

int main() {
    {
        Vehicle* v[4] = { new Bike(), new Rickshaw(), new CarEconomy(), new CarAC() };
        for (int i = 0; i < 4; i++) {
            std::cout << v[i]->getTag() << " " << v[i]->calculateFare(7.4) << "\n";
            delete v[i];
        }
    }
    std::cout << "live: " << Vehicle::liveCount << "\n";
    return 0;
}