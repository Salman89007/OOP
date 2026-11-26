#include <iostream>
#include <fstream>
#include <sstream>
#include "Distance.h"

int Distance::liveCount = 0;

Distance::Distance(std::string from, std::string to, double km)
    : from(from), to(to), km(km) { liveCount++; }

std::string Distance::getFrom() const { return from; }
std::string Distance::getTo() const { return to; }
double Distance::getKm() const { return km; }
Distance::~Distance() { liveCount--; }

int loadDistances(Collection<Distance>& table, const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file) {
        std::cout << "cannot open " << path << "\n";
        return 0;
    }
    int loaded = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string from, to, kmText, extra;

        if (!std::getline(ss, from, '|') ||
            !std::getline(ss, to, '|') ||
            !std::getline(ss, kmText, '|') ||
            std::getline(ss, extra, '|')) {
            std::cout << "corrupt line: " << line << "\n";
            continue;
        }

        double km;
        try {
            km = std::stod(kmText);          // throws if not a number
        } catch (...) {
            std::cout << "corrupt line: " << line << "\n";
            continue;
        }
        table.add(new Distance(from, to, km));
        loaded++;
    }
    return loaded;
}

double getDistance(const Collection<Distance>& table,
                   const std::string& from, const std::string& to) {
    for (int i = 0; i < table.size(); i++) {
        Distance* d = table.get(i);
        if (d->getFrom() == from && d->getTo() == to)
            return d->getKm();
    }
    return -1;
}