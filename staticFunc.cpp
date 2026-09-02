#include <iostream>
using namespace std;

class Employee{
    static int id;
    public:
    Employee(){
        id++;
    }
    void Print(){
        cout<<id<<endl;
    }
    static void PrintID(){
        cout<<"ID is : "<<id<<endl;
    }
};
int Employee::id = 0;//by default value is 0, no garbage

int main() {
    Employee e1;
    e1.Print();
    Employee::PrintID();
    Employee e2;
    e2.Print();
    Employee::PrintID();
    Employee e3;
    e3.Print();
    Employee::PrintID();
    
    return 0;
}