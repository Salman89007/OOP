#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
protected:
    char *name;
    double salary;

public:
    Employee()
    {
        name = nullptr;
        salary = 0;
    }
    Employee(double salary, const char *name) : salary(salary)
    {
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
    }
    Employee(const Employee &other)
    {
        int len = strlen(other.name);
        this->name = new char[len + 1];
        strcpy(this->name, other.name);

        this->salary = other.salary;
    }
    void show() const
    {
        cout << "Name : " << this->name << endl;
        cout << "Salary : " << this->salary << endl;
    }
    ~Employee()
    {
        delete[] name;
    }
};

class Manager : public Employee
{
private:
    int teamSize;

public:
    Manager(double salary, const char *name, int teamSize) : Employee(salary, name), teamSize(teamSize) {}
    void show() const
    {
        Employee::show();
        cout << "Team Size : " << teamSize << endl;
    }
    ~Manager() {}
};

int main()
{
    int n;
    cout << "enter n";
    cin >> n;

    Manager **arr = new Manager *[n];
    for (int i = 0; i < n; i++)
    {
        double salary;
        cout << "enter salary : " << endl;
        cin >> salary;

        int teamSize;
        cout << "enter team size" << endl;
        cin >> teamSize;

        cin.ignore();
        char buff[100];
        cout<<"enter name"<<endl;
        cin.getline(buff, 100);
        arr[i] = new Manager(salary, buff, teamSize);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]->show();
    }

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}