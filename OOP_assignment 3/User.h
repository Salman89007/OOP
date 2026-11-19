#ifndef USER_H
#define USER_H
#include <string>
#include "Wallet.h"

class User {
protected:
    std::string id, name, number, pin;
    Wallet wallet;
    double ratingTotal;
    int ratingCount;

public:
    User(std::string id, std::string name, std::string number, std::string pin,
         double walletBalance, double ratingTotal, int ratingCount);
    void addRating(int score);
    double getRating() const;
    virtual void showMenu() = 0;
    virtual ~User();
};

#endif