#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Zone.h"
#include "collection.h"

int main() {
    {
        Collection<Zone> zones;
        std::ifstream file("data/zones.txt");
        if (!file) {
            std::cout << "cannot open zones.txt\n";
            return 1;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;              // ignore blank lines

            std::stringstream ss(line);
            std::string id, name, extra;

            if (!std::getline(ss, id, '|') ||        // no first field
                !std::getline(ss, name, '|') ||      // no second field
                std::getline(ss, extra, '|')) {      // a third field exists
                std::cout << "corrupt line: " << line << "\n";
                continue;
            }
            zones.add(new Zone(id, name));
        }

        for (int i = 0; i < zones.size(); i++)
            std::cout << zones.get(i)->getID() << " " << zones.get(i)->getName() << "\n";
        std::cout << "count: " << zones.size() << "  (expect 8)\n";
    }
    std::cout << "live zones: " << Zone::liveCount << "  (expect 0)\n";
    return 0;
}