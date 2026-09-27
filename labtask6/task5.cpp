#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    double balance;
    bool isValidAmount(double amount)
    {
        if (amount > 0)
        {
            return true;
        }
        return false;
    }

public:
    BankAccount()
    {
        balance = 0;
    }
    void Deposit(double amount)
    {
        if (isValidAmount(amount) == true)
        {
            balance += amount;
        }
        else
        {
            cout << "amount is negative!!!"<<endl;
        }
    }
    void Withdraw(double amount)
    {
        if (isValidAmount(amount) == true)
        {
            if (balance<amount)
            {
                cout<<"can't withdraw , balance insufficient"<<endl;
            }else{
                balance -= amount;
            }
        }
        else{
            cout<<"amount is negative!!!"<<endl;
        }
    }
    double get_balance() const
    {
        return balance;
    }
};
int main()
{
    BankAccount B;
    B.Deposit(-1000);
    cout << B.get_balance() << endl;
    B.Withdraw(1001);
    cout << B.get_balance() << endl;
    B.Withdraw(500);
    cout << B.get_balance() << endl;
    return 0;
}