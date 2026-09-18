#include <iostream>
using namespace std;

struct Employee
{
    int id;
    float salary;
};
float avgSalary(Employee *arr, int size)
{
    float sum = 0;
    float average;
    for (int i = 0; i < size; i++)
    {
        arr[i].id = i+1;
        arr[i].salary = (i+1) * 1000;
    }
    for (int i = 0; i < size; i++)
    {
        sum += arr[i].salary;
    }
    average = sum/(float)size;
    return average;
}

int main()
{
    Employee e[3];
    Employee *emp = e;
    cout<<"Average is : "<<avgSalary(emp,3);
    return 0;
}