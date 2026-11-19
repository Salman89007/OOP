#include <iostream>
#include "User.h"

class TestUser : public User {
public:
    TestUser(double bal, double total, int count)
        : User("P001", "Ali", "0300", "1234", bal, total, count) {}
    void showMenu() {}
    double balance() const { return wallet.getBalance(); }
};

int main() {
    TestUser a(1450.0, 47.0, 10);
    std::cout << "balance: " << a.balance() << "  (expect 1450)\n";
    std::cout << "rating:  " << a.getRating() << "  (expect 4.7)\n";

    a.addRating(5);
    std::cout << "rating after 5: " << a.getRating() << "  (expect 4.72727)\n";

    TestUser b(0, 0, 0);
    std::cout << "empty rating: " << b.getRating() << "  (expect 0)\n";
    return 0;
}