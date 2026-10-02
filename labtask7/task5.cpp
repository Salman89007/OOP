#include <iostream>
#include <cstring>
using namespace std;
class Logger{
	private:
	char* name;
	public:
	Logger(){
		name = new char[20];
		strcpy(name,"");
	}

	void setter(char* n){
		name = new char[20];
		strcpy(name,n);
	}
	const char* getName() const 
	{ 
	    return name; 
	}
	
};

int main(){
	Logger L1;
	L1.setter("Bruce wayne");
	Logger L2 = L1;
	L2.setter("Clark Kent");
	cout<<L1.getName()<<endl;
	cout<<L2.getName()<<endl;
	return 0;
}