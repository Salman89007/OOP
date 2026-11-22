
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CurrencyAmount
{
protected:
    string currencyCode;
    double amount;

public:
    CurrencyAmount(string code, double amt) : currencyCode(code), amount(amt) {}

    CurrencyAmount operator+(CurrencyAmount rhs)
    {
        if (this->currencyCode == rhs.currencyCode)
        {
            CurrencyAmount temp(currencyCode, 0.0);
            temp.amount = amount + rhs.amount;
            return temp;
        }
        else
        {
            cout << "currency code does not matches!" << endl;
            return CurrencyAmount("ERR", 0.0);
        }
    }

    CurrencyAmount operator-(CurrencyAmount rhs)
    {
        if (this->currencyCode == rhs.currencyCode)
        {
            CurrencyAmount temp(currencyCode, 0.0);
            temp.amount = amount - rhs.amount;
            return temp;
        }
        else
        {
            cout << "currency code does not matches!" << endl;
            return CurrencyAmount("ERR", 0.0);
        }
    }

    CurrencyAmount &operator+=(CurrencyAmount rhs)
    {
        if (this->currencyCode == rhs.currencyCode)
        {
            this->amount += rhs.amount;
        }
        else
        {
            cout << "currency code does not matches!" << endl;
        }
        return *this;
    }

    bool operator==(CurrencyAmount rhs)
    {
        if (this->currencyCode == rhs.currencyCode && abs(this->amount - rhs.amount) < 0.001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream &operator<<(ostream &out, CurrencyAmount c)
    {
        out << "[" << c.currencyCode << " " << fixed << setprecision(2) << c.amount << "]";
        return out;
    }
};

int main()
{
    CurrencyAmount c1("USD", 1000);
    CurrencyAmount c2("USD", 500);
    CurrencyAmount c3("EUR", 10000);

    CurrencyAmount c4 = c1 + c2;
    cout << "Addition: " << c4 << endl;

    CurrencyAmount c5 = c1 - c2;
    cout << "Subtraction: " << c5 << endl;

    CurrencyAmount wallet1("USD", 1000);
    CurrencyAmount wallet2("USD", 500);
    CurrencyAmount wallet3("USD", 250);

    wallet1 += wallet2 += wallet3;
    cout << "Chained +=: " << wallet1 << endl;
    cout << "Wallet2: " << wallet2 << endl;

    if (c1 == c2)
    {
        cout << "Amounts are equal" << endl;
    }
    else
    {
        cout << "Amounts are not equal" << endl;
    }
    CurrencyAmount c6 = c1 + c3;
    cout << "Mismatched addition: " << c6 << endl;

    wallet1 += c3;

    return 0;
}
