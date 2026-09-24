#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string roll_number;
    float CGPA;
};
Student *AddFunc(Student **&s, int &capacity, int &count, string name, string rollnumber, float cgpa)
{
    int newSize;
    if (capacity == count)
    {
        newSize = capacity * 2;
        Student **S = new Student *[newSize];

        for (int i = 0; i < count; i++)
        {
            S[i] = s[i];
        }
        delete[] s;
        s = S;
        capacity = newSize;
    }
    s[count] = new Student;
    s[count]->name = name;
    s[count]->roll_number = rollnumber;
    s[count]->CGPA = cgpa;
    count++;
    return s[count - 1];
}
Student *SearchStudent(Student **&s, int count, string rollnumber)
{
    for (int i = 0; i < count; i++)
    {
        if (s[i]->roll_number == rollnumber)
        {
            return s[i];
        }
    }
    return nullptr;
}
int main()
{
    int capacity;
    cout << "enter size : ";
    cin >> capacity;
    if (capacity < 1) capacity = 1;
    Student **S = new Student *[capacity];

    int count = 0;
    int n;
    cout << "Capacity is " << capacity << ", enter how much data you want to store? : ";
    cin >> n;

    string name, roll;
    float cgpa;

    for (int i = 0; i < n; i++)
    {
        cout << "enter name : ";
        cin >> name;
        cout << "enter roll : ";
        cin >> roll;
        cout << "enter CGPA : ";
        cin >> cgpa;

        Student *ptr = AddFunc(S, capacity, count, name, roll, cgpa);
    }

    string Roll_number;
    cout << "enter roll number to search for : ";
    cin >> Roll_number;

    Student *found = SearchStudent(S, count, Roll_number);

    if (found != nullptr){
        cout << found->name << " " << found->CGPA << endl;
    }   
    else{
        cout << "not found" << endl;
    }

    for (int i = 0; i < count; i++)
    {
        delete S[i];
    }
    delete[] S;
    return 0;
}