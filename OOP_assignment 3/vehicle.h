#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
protected:
    double base, rate, minimum;

public:
    static int liveCount;
    Vehicle(double base, double rate, double minimum) : base(base), rate(rate), minimum(minimum)
    {
        liveCount++;
    }
    virtual double calculateFare(double km) const
    {
        double fare = base + rate * km;
        if (fare < minimum)
        {
            return minimum;
        }
        return fare;
    }
    virtual std::string getTag() const = 0;
    virtual ~Vehicle() {liveCount--;}
};

#endif