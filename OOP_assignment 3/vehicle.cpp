#include <iostream>
#include "vehicle.h"
#include "bike.h"
#include "rickshaw.h"
#include "CarEconomy.h"
using namespace std;
int main()
{
    Rickshaw r;
    CarEconomy c;
    cout << r.getTag() << " " << r.calculateFare(7.4) << endl;
    cout << c.getTag() << " " << c.calculateFare(7.4) << endl;
    return 0;
}