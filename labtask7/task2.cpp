#include <iostream>
#include <string>
using namespace std;
class Logger{
	private:
	string name;
	public:
	Logger(string Name){
		name = Name;
		cout<<name<<"Object created"<<endl;
	}
	~Logger(){
		cout<<name<<"Object destroyed"<<endl;
	}
};
void localFunc(){
	Logger local("Local ");
	cout<<"inside local function "<<endl;
	
}
int main(){
	Logger local("Main ");
	localFunc();
	return 0;
}