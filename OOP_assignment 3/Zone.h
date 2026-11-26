#ifndef ZONE_H
#define ZONE_H

#include <string>

class Zone
{
protected:
    std::string id, name;

public:
    static int liveCount;
    Zone(std::string id, std::string name) : id(id), name(name) {
        liveCount++;
    };

    std::string getID()
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    ~Zone() { liveCount--; }
};


#endif