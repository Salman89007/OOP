#include <iostream>
#include <string>
using namespace std;
class Employee{
    private:
    string name;
	int ID;
	double pay;
	public:
	void set_name(string Name)
    {
        name = Name;
    }
    void set_ID(int id)
    {
        ID = id;
    }
	void set_pay(float Pay)
    {
        pay = Pay;
    }	
	string get_name() const 
    {
        return name;
    }
    int get_ID() const 
    {
        return ID;
    }
    double get_Pay() const 
    {
        return pay;
    }
};

int main() {
	Employee E;
	E.set_name("john");
	E.set_ID(1);
	E.set_pay(1000.00);
	Employee *emp = new Employee;
	
	emp->set_name("Mark");
	emp->set_ID(2);
	emp->set_pay(2000.00);
	
	cout<<"Name is : "<<E.get_name()<<endl;
    cout<<"ID is : "<<E.get_ID()<<endl;
    cout<<"Pay is : "<<E.get_Pay()<<endl;
    
    cout<<"Name is : "<<emp->get_name()<<endl;
    cout<<"ID is : "<<emp->get_ID()<<endl;
    cout<<"Pay is : "<<emp->get_Pay()<<endl;
	
    return 0;
}