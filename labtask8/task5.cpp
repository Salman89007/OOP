#include <iostream>
using namespace std;

class Wallet{
	double balance;
	public:
	Wallet(double balance){
		this->balance = balance;
	}
	friend void transferFunds(Wallet &from, Wallet &to, double amount);
	void Display(){
		cout<<"Balance : "<<this->balance<<endl;
	}
};

void transferFunds(Wallet &from, Wallet &to, double amount){
	from.balance -= amount;
	to.balance += amount;
}

int main(){
	
	Wallet W1(1000);
	Wallet W2(2000);
	W1.Display();
	W2.Display();
	double amount;
	cout<<"Enter Anount : ";
	cin>>amount;
	transferFunds(W1,W2,amount);
	W1.Display();
	W2.Display();
	
	return 0;
}