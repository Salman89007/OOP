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
    virtual void displayInfo() = 0; // pure virtual — Person is now abstract
    virtual ~Person()
    {
        cout << name << " (Person) destroyed" << endl;
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
    void displayInfo() override
    {

        cout << "ID: " << ID << ", Name: " << name << ", Age: " << age << endl;
        cout << "Appointment: " << appointment_date << " #" << appointment_number
             << ", Issue: " << issue << endl;
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
    void displayInfo() override
    {

        cout << "ID: " << ID << ", Name: " << name << ", Age: " << age << endl;
        cout << "specialization: " << specialization << ",doctor_number #" << doctor_number << endl;
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
    void displayInfo() override
    {
        Doctor::displayInfo();
        cout << "surgeon_specialization: " << surgeon_specialization << endl;
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
    void displayInfo() override
    {
        Doctor::displayInfo();
        cout << "Physician: " << Physician << endl;
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
    void displayInfo() override
    {

        cout << "ID: " << ID << ", Name: " << name << ", Age: " << age << endl;
        cout << "staff_shift: " << staff_shift << ",staff_number #" << staff_number << endl;
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
    void displayInfo() override
    {
        Staff::displayInfo();
        cout << "Nurse_shift: " << Nurse_shift << ", Nurse_number: " << Nurse_number << endl;
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
    void displayInfo() override
    {
        Staff::displayInfo();
        cout << "Receptionist_shift: " << Receptionist_shift << ", Receptionist_number: " << Receptionist_number << endl;
    }
};

int main()
{
    Person *people[5];
    people[0] = new Patient(1, "Ali", 30, "2026-09-10", 101, "Fever", nullptr);
    people[1] = new Surgeon(2, "Dr. Khan", 45, "Surgery", 501, "Cardiothoracic");
    people[2] = new GeneralPhysician(3, "Dr. Iqbal", 40, "General", 502, "Internal Medicine");
    people[3] = new Nurse(4, "Sara", 25, "Day", 201, "Night", 301);
    people[4] = new Receptionist(5, "Ayesha", 22, "Day", 202, "Morning", 401);

    for (int i = 0; i < 5; i++)
    {
        people[i]->displayInfo();
        cout << "-----------------" << endl;
    }

    for (int i = 0; i < 5; i++)
        delete people[i];

    return 0;
}