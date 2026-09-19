#include <iostream>
using namespace std;

struct Employee
{
    string name;
    int salary;
};

void IncSalary(Employee *E, int n, int percent)
{
    for (int i = 0; i < n; i++)
    {
        E[i].salary += E[i].salary * percent / 100;
    }
}
int main()
{
    int n;
    cout << "enter number of people : ";
    cin >> n;
    cin.ignore();
    Employee E[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name : ";
        getline(cin, E[i].name);

        cout << "Enter salary : ";
        cin >> E[i].salary;
        cin.ignore();
    }

    int percent;
    cout << "enter how much increase to give : ";
    cin >> percent;

    IncSalary(E, n, percent);
    cout<<"salaries after increase"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<"salary of "<<E[i].name<<" : "<<E[i].salary<<endl;
    }
    

    return 0;
}