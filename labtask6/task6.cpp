#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
    string name;
    double price;

public:
    void set_name(string Name)
    {
        name = Name;
    }
    void set_price(double Price)
    {
        price = Price;
    }
    string get_name() const
    {
        return name;
    }
    double get_price() const
    {
        return price;
    }
};
void applyDiscount(Product *p, double percent)
{
    double price[3];
    for (int i = 0; i < 3; i++)
    {
        price[i] = p[i].get_price();
        price[i] *= (percent/100.00);
        p[i].set_price(p[i].get_price()-price[i]);
    }
}
int main()
{
    Product P[3];
    for (int i = 0; i < 3; i++)
    {
        string name;
        double price;
        cin >> name;
        cin >> price;
        P[i].set_name(name);
        P[i].set_price(price);
    }

    cout<<"before applying discount"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "name is : " << P[i].get_name() << endl;
        cout << "price is : " << P[i].get_price() << endl;
    }
    double discount;
    cout<<"enter discount to give in percentage : "<<endl;
    cin>>discount;

    applyDiscount(P, discount);

    cout<<"after applying discount"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "name is : " << P[i].get_name() << endl;
        cout << "price is : " << P[i].get_price() << endl;
    }

    return 0;
}