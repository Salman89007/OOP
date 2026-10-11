#include <iostream>
#include <string>
using namespace std;

class Account{
	double balance;
	string owner_name;
	int ID;
	public:
	Account(double balance, string owner_name,int ID){
		this->balance = balance;
		this->owner_name = owner_name;
		this->ID = ID;
	}
	double getBalance() const{
		return balance;
	}
	string getOWner_name() const{
		return owner_name;
	}
};

int main(){
	const Account A(1000,"John",1);
	cout<<"Balance =  "<<A.getBalance()<<endl;
	cout<<"Owner name = "<<A.getOWner_name()<<endl;
	
	return 0;
}