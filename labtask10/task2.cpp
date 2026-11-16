#include <iostream>
using namespace std;

class PaymentGateway{
	protected:
	double amount;
	public:
	PaymentGateway(double amount) : amount(amount){
	}
	virtual void processPayment() = 0;
	virtual ~PaymentGateway(){
		cout<<"PaymentGateway Destroyed "<<endl;
	}
};

class CreditCardPayment : public PaymentGateway{
	string* auditLog;
	int logSize;
	public:
	CreditCardPayment(double amount) : PaymentGateway(amount){
		logSize = 3;
		auditLog = new string[logSize];
		auditLog[0] = "Card verified";
		auditLog[1] = "Amount authorized";
		auditLog[2] = "Transaction completed";
	}
	void processPayment(){
		cout<<"Processing credit card payment of "<<amount<<endl;
		for(int i = 0; i < logSize; i++){
			cout<<"Log : "<<auditLog[i]<<endl;
		}
	}
	~CreditCardPayment(){
		delete[] auditLog;
		cout<<"CreditCardPayment Destroyed "<<endl;
	}
	
};

class PayPalPayment : public PaymentGateway{
	string* auditLog;
	int logSize;
	public:
	PayPalPayment(double amount) : PaymentGateway(amount){
		logSize = 2;
		auditLog = new string[logSize];
		auditLog[0] = "PayPal account linked";
		auditLog[1] = "Transaction completed";
	}
	void processPayment(){
		cout<<"Processing PayPal payment of "<<amount<<endl;
		for(int i = 0; i < logSize; i++){
			cout<<"Log : "<<auditLog[i]<<endl;
		}
	}
	~PayPalPayment(){
		delete[] auditLog;
		cout<<"PayPalPayment Destroyed "<<endl;
	}
};

int main(){
	PaymentGateway*ptr[2];
	ptr[0]= new CreditCardPayment(300000);
	ptr[1]= new PayPalPayment(500000);
	for(int i = 0; i < 2; i++){
		ptr[i]->processPayment();
	}
	delete ptr[0];
	delete ptr[1];
	return 0;
}