#ifndef WALLET_H
#define WALLET_H

class Wallet {
private:
    double balance;               // private: nobody outside can assign it (R3)
public:
    Wallet(double start = 0);     // default value 0
    void topUp(double amount);
    bool deduct(double amount);
    double getBalance() const;
};

#endif