#include <iostream>
#include <string>
using namespace std;
class Student{
    private:
    string name;
    int marks;
    public:
    void set_name(string Name)
    {
        name = Name;
    }
    void set_marks(int Marks)
    {
        marks = Marks;
    }
    string get_name() const 
    {
        return name;
    }
    int get_marks() const
    {
        return marks;
    }
};
int main() {
    Student S;
    S.set_name("John");
    S.set_marks(50) ;
    cout<<"Name is : "<<S.get_name()<<endl;
    cout<<"Marks are : "<<S.get_marks();
    
    return 0;
}