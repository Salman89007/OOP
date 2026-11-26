#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>
#include "collection.h"

class Distance {
private:
    std::string from, to;
    double km;

public:
    static int liveCount;
    Distance(std::string from, std::string to, double km);
    std::string getFrom() const;
    std::string getTo() const;
    double getKm() const;
    ~Distance();
};

// Loads data/distances.txt into the collection; returns number loaded.
int loadDistances(Collection<Distance>& table, const std::string& path);

// Returns km between two zones, or -1 if not found.
double getDistance(const Collection<Distance>& table,
                   const std::string& from, const std::string& to);

#endif