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
};
class Bank
{
    int vault;

public:

    friend void transfer(Wallet &w, Bank &b, int amount);
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

int main()
{
    Wallet w(5000);
    Bank b;
    int amount;
    cout<<"enter amount"<<endl;
    cin>>amount;
    transfer(w,b,amount);


    return 0;
}