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
protected:
    string appointment_date;
    int appointment_number;
    string issue;
    int *Doctor_number;

public:
    Patient(int ID, string name, int age, string appointment_date, int appointment_number,
            string issue, int *Doctor_number) : Person(ID, name, age)
    {
        this->appointment_date = appointment_date;
        this->appointment_number = appointment_number;
        this->issue = issue;
        this->Doctor_number = Doctor_number;
    }
};

class Doctor : public Person
{
protected:
    string specialization;
    int doctor_number;

public:
    Doctor(int ID, string name, int age, string specialization, int doctor_number) : Person(ID, name, age)
    {
        this->specialization = specialization;
        this->doctor_number = doctor_number;
    }
};
class Surgeon : public Doctor
{
protected:
    string surgeon_specialization;

public:
    Surgeon(int ID, string name, int age, string specialization, int doctor_number, string surgeon_specialization) : Doctor(ID, name, age, specialization, doctor_number)
    {
        this->surgeon_specialization = surgeon_specialization;
    }
};
class GeneralPhysician : public Doctor
{
protected:
    string Physician;

public:
    GeneralPhysician(int ID, string name, int age, string specialization, int doctor_number, string Physician) : Doctor(ID, name, age, specialization, doctor_number)
    {
        this->Physician = Physician;
    }
};
class Staff : public Person
{
protected:
    string staff_shift;
    int staff_number;

public:
    Staff(int ID, string name, int age, string staff_shift, int staff_number) : Person(ID, name, age)
    {
        this->staff_shift = staff_shift;
        this->staff_number = staff_number;
    }
};
class Nurse : public Staff
{
protected:
    string Nurse_shift;
    int Nurse_number;

public:
    Nurse(int ID, string name, int age, string staff_shift, int staff_number, string Nurse_shift, int Nurse_number) : Staff(ID, name, age, staff_shift, staff_number)
    {
        this->Nurse_shift = Nurse_shift;
        this->Nurse_number = Nurse_number;
    }
};
class Receptionist : public Staff
{
protected:
    string Receptionist_shift;
    int Receptionist_number;

public:
    Receptionist(int ID, string name, int age, string staff_shift, int staff_number, string Receptionist_shift, int Receptionist_number) : Staff(ID, name, age, staff_shift, staff_number)
    {
        this->Receptionist_shift = Receptionist_shift;
        this->Receptionist_number = Receptionist_number;
    }
};

int main()
{

    return 0;
}