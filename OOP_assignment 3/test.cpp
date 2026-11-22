#include <iostream>
#include "Driver.h"

int main() {
    std::cout << "before: " << Driver::liveCount << "  (expect 0)\n";
    {
        Driver d("D001", "Bilal", "0301", "4321", 2000.0, 47.0, 10, "BIKE");
        std::cout << "inside: " << Driver::liveCount << "  (expect 1)\n";
        d.showMenu();
    }
    std::cout << "after:  " << Driver::liveCount << "  (expect 0)\n";
    return 0;
}