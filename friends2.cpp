#include <iostream>
using namespace std;

class Bank;

class Wallet
{
    int cash;

public:
    Wallet(int cash)
    {
        this->cash = cash;
    }
    friend void transfer(Wallet &w, Bank &b, int amount);
    friend void Print(const Wallet &w, const Bank &b);
};
class Bank
{
    int vault = 0;

public:
    Bank(int vault)
    {
        this->vault = vault;
    }

    friend void transfer(Wallet &w, Bank &b, int amount);
    friend void Print(const Wallet &w, const Bank &b);
};
void transfer(Wallet &w, Bank &b, int amount)
{
    if (w.cash < amount)
    {
        cout << "insufficient funds" << endl;
    }
    w.cash -= amount;
    b.vault += amount;
}
void Print(const Wallet &w, const Bank &b)
{
    cout << "cash : " << w.cash << endl;
    cout << "in vault : " << b.vault << endl;
}
int main()
{
    Wallet w(100);
    Bank b(30);
    int amount;
    cout << "enter amount" << endl;
    cin >> amount;
    transfer(w, b, amount);
    Print(w, b);
    return 0;
}