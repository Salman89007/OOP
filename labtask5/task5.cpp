#include <iostream>
#include <string>
using namespace std;

struct Address
{
    string city;
    string street;
};

struct Employee
{
    Address A;
};

Employee *Search(Employee *E,int n)
{

    string city;
    cout << "enter city name to search for : ";
    getline(cin, city);

    for (int i = 0; i < n; i++)
    {
        if (E[i].A.city == city)
        {
            return &E[i];
        }
    }
    return nullptr;
}

int main()
{
    int n;
    cout<<"enter number of Employees "<<endl;
    cin>>n;
    cin.ignore();
    Employee *E = new Employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter Employee " << i + 1 << " city name : ";
        getline(cin, E[i].A.city);

        cout << "enter Employee " << i + 1 << " street name : ";
        getline(cin, E[i].A.street);
    }

    Employee *pointer = Search(E, n);
    if (pointer == nullptr)
    {
        cout << "Not found !" << endl;
    }
    else
    {
        cout << "found ! " << endl;
        cout<<"enter a new street name "<<endl;
        getline(cin, pointer->A.street);
        cout << "Changed street is now " << pointer->A.street << endl;
    }
    delete[] E;

    return 0;
}