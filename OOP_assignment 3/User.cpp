#include "User.h"
User::User(std::string id, std::string name, std::string number, std::string pin,
           double walletBalance, double ratingTotal, int ratingCount)
    : id(id), name(name), number(number), pin(pin),
      wallet(walletBalance), ratingTotal(ratingTotal), ratingCount(ratingCount) {}
void User::addRating(int score)
{
    ratingTotal += score;
    ratingCount++;
}

double User::getRating() const
{
    if (ratingCount == 0)
        return 0;
    return ratingTotal / ratingCount;
}
User::~User() {}