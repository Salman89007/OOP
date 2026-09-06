#include <iostream>
#include <string>
using namespace std;
class Person
{ // person is common to all
protected:
    int ID;
    string name;
    int age;

public:
    Person(int ID, string name, int age)
    {
        this->ID = ID;
        this->name = name;
        this->age = age;
    }
    ~Person()
    {
        cout << "constructor Person Destroyed" << endl;
    }
};
class Patient : public Person
{
    string appointment_date;
    int appointment_number;
    string issue;
    int *Doctor_number;

public:
    Patient(int ID, string name, int age, string appointment_date,int appointment_number, 
    string issue, int Doctor_number) : 
    Person(ID, name, age)
    {

    }
};

class Doctor : public Person
{
};
class Surgeon : public Doctor
{
};
class GeneralPhysician : public Doctor
{
};
class Staff : public Person
{
};
class Nurse : public Staff
{
};
class Receptionist : public Staff
{
};

int main()
{

    return 0;
}