#include <iostream>
#include <cstring>
using namespace std;
class Person{
	private:
	char *name;
	
	public:
	void setter(const char* n)
	{
	    strcpy(name,n);
	}
	Person(const char* n)
	{
	    name = new char[20];
	    strcpy(name,n);
	}
	Person(Person &other)
	{
	    name = new char[20];
	    strcpy(name,other.name);
	    
	}
	const char* getName()const {
	    return name;
	}
	~Person(){delete[] name;}
};

int main(){
    Person P1("salman");
    Person P2 = P1;
    P2.setter("Bruce wayne");
    
    cout<<P1.getName()<<endl;
    cout<<P2.getName()<<endl;
	
	return 0;
}