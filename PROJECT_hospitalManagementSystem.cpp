#include <iostream>
#include <string>
using namespace std;

class Doctor;

class Person
{ // person is common to all
protected:
    int ID;
    string name;
    int age;
    double salary;
    static int nextID;
    static int totalPeople;

public:
    Person(string name, int age)
    {
        this->ID = nextID++;
        this->name = name;
        this->age = age;
        this->salary = 0;
        totalPeople++;
    }

    virtual void displayInfo() = 0;               // pure virtual(polymorphism) — Person is now abstract
    virtual double GiveSalary(double amount) = 0; // now there are two conditions for abstract, displayInfo and giveSalary()
    virtual ~Person()
    {
        cout << name << " (Person) destroyed" << endl;
        totalPeople--;
    }
};

class Patient : public Person
{
protected:
    string appointment_date;
    int appointment_number;
    string issue;
    Doctor *Doctor_number;

public:
    Patient(string name, int age, string appointment_date, int appointment_number,
            string issue, Doctor *Doctor_number) : Person(name, age)
    {
        this->appointment_date = appointment_date;
        this->appointment_number = appointment_number;
        this->issue = issue;
        this->Doctor_number = Doctor_number;
    }
    double GiveSalary(double amount) override { return 0; }
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
    Doctor(string name, int age, string specialization, int doctor_number) : Person(name, age)
    {
        this->specialization = specialization;
        this->doctor_number = doctor_number;
    }
    void displayInfo() override = 0;
};
class Surgeon : public Doctor
{
protected:
    string surgeon_specialization;

public:
    Surgeon(string name, int age, string specialization, int doctor_number, string surgeon_specialization) : Doctor(name, age, specialization, doctor_number)
    {
        this->surgeon_specialization = surgeon_specialization;
    }
    double GiveSalary(double amount) override
    {
        salary = amount;
        return salary;
    }
    void displayInfo() override
    {
        Doctor::displayInfo();
        cout << "surgeon_specialization: " << surgeon_specialization << "surgeon salary : " << salary << endl;
    }
};
class GeneralPhysician : public Doctor
{
protected:
    string Physician;

public:
    GeneralPhysician(string name, int age, string specialization, int doctor_number, string Physician) : Doctor(name, age, specialization, doctor_number)
    {
        this->Physician = Physician;
    }
    double GiveSalary(double amount) override
    {
        salary = amount;
        return salary;
    }
    void displayInfo() override
    {
        Doctor::displayInfo();
        cout << "Physician: " << Physician << ", Physician salary : " << salary << endl;
    }
};
class Staff : public Person
{
protected:
    string staff_shift;
    int staff_number;

public:
    Staff(string name, int age, string staff_shift, int staff_number) : Person(name, age)
    {
        this->staff_shift = staff_shift;
        this->staff_number = staff_number;
    }
    void displayInfo() override = 0;
};
class Nurse : public Staff
{
protected:
    string Nurse_shift;
    int Nurse_number;

public:
    Nurse(string name, int age, string staff_shift, int staff_number, string Nurse_shift, int Nurse_number) : Staff(name, age, staff_shift, staff_number)
    {
        this->Nurse_shift = Nurse_shift;
        this->Nurse_number = Nurse_number;
    }
    double GiveSalary(double amount) override
    {
        salary = amount;
        return salary;
    }
    void displayInfo() override
    {
        Staff::displayInfo();
        cout << "Nurse_shift: " << Nurse_shift << ", Nurse_number: " << Nurse_number << ", Nurse_salary: " << salary << endl;
    }
};
class Receptionist : public Staff
{
protected:
    string Receptionist_shift;
    int Receptionist_number;

public:
    Receptionist(string name, int age, string staff_shift, int staff_number, string Receptionist_shift, int Receptionist_number) : Staff(name, age, staff_shift, staff_number)
    {
        this->Receptionist_shift = Receptionist_shift;
        this->Receptionist_number = Receptionist_number;
    }
    double GiveSalary(double amount) override
    {
        salary = amount;
        return salary;
    }
    void displayInfo() override
    {
        Staff::displayInfo();
        cout << "Receptionist_shift: " << Receptionist_shift << ", Receptionist_number: " << Receptionist_number << ", Receptionist_salary: " << salary << endl;
    }
};

void Doctor::displayInfo()
{

    cout << "ID: " << ID << ", Name: " << name << ", Age: " << age << endl;
    cout << "specialization: " << specialization << ",doctor_number #" << doctor_number << endl;
}
void Staff::displayInfo()
{
    cout << "ID: " << ID << ", Name: " << name << ", Age: " << age << endl;
    cout << "staff_shift: " << staff_shift << ",staff_number #" << staff_number << endl;
}
int Person::nextID = 1;
int Person::totalPeople = 0;

class Hospital
{
private:
    Person **people;
    string name;
    int count;
    int capacity;

public:
    Hospital(string name, int capacity) : name(name), count(0), capacity(capacity)
    {
        people = new Person *[capacity];
    }
    Hospital(const Hospital &) = delete;
    void addPerson(Person *p, double salary = 0)
    {
        p->GiveSalary(salary);
        if (count == capacity)
        {
            capacity *= 2;
            Person **temp = new Person *[capacity];
            for (int i = 0; i < count; i++)
                temp[i] = people[i];
            delete[] people;
            people = temp;
        }
        people[count++] = p;
    }
    void showAll()
    {
        for (int i = 0; i < count; i++)
        {
            people[i]->displayInfo();
            cout << "-----------------" << endl;
        }
    }

    ~Hospital()
    {
        for (int i = 0; i < count; i++)
            delete people[i];
        delete[] people;
    }
};
int main()
{
    int capacity;
    cout<<"enter capacity : "<<endl;
    cin>>capacity;
    Hospital h("City Hospital",capacity);

    h.addPerson(new Patient("Ali", 30, "2026-09-10", 101, "Fever", nullptr));
    h.addPerson(new Surgeon("Dr. Khan", 45, "Surgery", 501, "Cardiothoracic"), 50000);
    h.addPerson(new GeneralPhysician("Dr. Iqbal", 40, "General", 502, "Internal Medicine"), 30000);
    h.addPerson(new Nurse("Sara", 25, "Day", 201, "Night", 301), 5000);
    h.addPerson(new Receptionist("Ayesha", 22, "Day", 202, "Morning", 401), 2000);

    h.showAll();
    return 0;
}