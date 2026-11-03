#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    int id;

public:
    Person(string name, int id) : name(name), id(id) {}
    void Display()
    {
        cout << "name : " << this->name << endl;
        cout << "id : " << this->id << endl;
    }
    ~Person() {}
};
class Student : virtual public Person
{
protected:
    float cgpa;
    int semester;

public:
    Student(string name, int id, float cgpa, int semester) : cgpa(cgpa), semester(semester), Person(name, id) {}
    void Display()
    {
        Person::Display();
        cout << "cgpa : " << this->cgpa << endl;
        cout << "semester : " << this->semester << endl;
    }
};
class Employee : virtual public Person
{
protected:
    double baseSalary;

public:
    Employee(string name, int id, double baseSalary) : Person(name, id), baseSalary(baseSalary) {}

    double calculateSalary()
    {
        return baseSalary;
    }

    void Display()
    {
        Person::Display();
        cout << "base salary : " << this->baseSalary << endl;
    }
};
class Faculty : public Employee
{
protected:
    string department;
    int courseCount;
    double salary;

public:
    Faculty(string name, int id, double baseSalary, string department, int courseCount) : Person(name, id), Employee(name, id, baseSalary), department(department), courseCount(courseCount) {}
    double calculateSalary()
    {
        salary = Employee::calculateSalary() + 5000 * courseCount;
        return salary;
    }
    void Display()
    {
        Employee::Display();
        cout << "department : " << department << endl;
        cout << "courses : " << courseCount << endl;
    }
};
class Professor : public Faculty
{
protected:
    int researchPapers;

public:
    Professor(string name, int id, double baseSalary, string department, int courseCount, int researchPapers) : Person(name, id), Faculty(name, id, baseSalary, department, courseCount), researchPapers(researchPapers) {}
    double calculateSalary()
    {
        return Faculty::calculateSalary() + 2000 * researchPapers;
    }
    void Display()
    {
        Faculty::Display();
        cout << "research papers : " << researchPapers << endl;
    }
};
class staff : public Employee
{
protected:
    int overtimeHours;

public:
    staff(string name, int id, double baseSalary, int overtimeHours) : Person(name, id), Employee(name, id, baseSalary), overtimeHours(overtimeHours) {}
    double calculateSalary()
    {
        return baseSalary + 300 * overtimeHours;
    }
    void Display()
    {
        Employee::Display();
        cout << "overtime hours : " << overtimeHours << endl;
    }
};
class TeachingAssistant : public Student, public Employee
{
protected:
    int hoursPerWeek;

public:
    TeachingAssistant(string name, int id, float cgpa, int semester, double baseSalary, int hoursPerWeek) : Person(name, id), Student(name, id, cgpa, semester), Employee(name, id, baseSalary), hoursPerWeek(hoursPerWeek) {}
    double calculateSalary()
    {
        return (0.4 * baseSalary) + 500 * hoursPerWeek;
    }
    void Display()
    {
        Person::Display();
        cout << "cgpa : " << this->cgpa << endl;
        cout << "semester : " << this->semester << endl;
        cout << "base salary : " << this->baseSalary << endl;
        cout << "hours per week : " << hoursPerWeek << endl;
    }
};
int main()
{
    Student S("salman", 1, 3.45, 3);
    Faculty F("jabbar", 3, 20000, "CS", 5);
    Professor P("Ali", 10, 50000, "CS", 9, 12);
    staff s("hassan",5, 2000, 2);
    TeachingAssistant TA("haider", 23, 3, 7, 30000, 7);
    S.Display();
    F.Display();
    P.Display();
    s.Display();
    TA.Display();

    double total = F.calculateSalary() + P.calculateSalary() + s.calculateSalary() + TA.calculateSalary();
    cout << "Total payout: " << total << endl;

    cout << sizeof(TeachingAssistant);

    return 0;
}