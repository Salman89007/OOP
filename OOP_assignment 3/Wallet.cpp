#include "Wallet.h"

Wallet::Wallet(double balance) : balance(balance) {}

void Wallet::topUp(double amount)
{

    if (amount > 0)
    {
        balance += amount;
    }
}

bool Wallet::deduct(double amount)
{
    if (amount > balance)
    {
        return false;
    }
    else
    {
        balance -= amount;
        return true;
    }
}

double Wallet::getBalance() const
{
    return balance;
}