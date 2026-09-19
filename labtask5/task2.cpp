#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int quantity;
    int price;
};

double Total(const Item *I, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += I[i].price * I[i].quantity;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"enter number of people : ";
    cin>>n;
    cin.ignore();

    Item I[n];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name : ";
        getline(cin, I[i].name);

        cout << "Enter quantity : ";
        cin >> I[i].quantity;

        cout << "Enter price : ";
        cin >> I[i].price;
        cin.ignore();
    }

    double total = Total(I,n);

    cout << "sum is " << total << endl;

    return 0;
}