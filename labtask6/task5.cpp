#include <iostream>
#include <string>
using namespace std;
class BankAccount{
    private:
    double balance;
    bool isValidAmount(double amount){
    	if(amount < 0){
    		return true;
		}
		return false;
	}
    public:
    void Deposit(double amount){
    	if(isValidAmount(amount) == true){
    		cout<<"low balance ! ";
		}else{
			balance += amount;
		}
	}
	void Withdraw(double amount){
    	if(isValidAmount(amount) == true){
    		cout<<"low balance ! ";
		}else{
			balance -= amount;
		}
	}
	double get_balance() const{
		return balance;
	}
};
int main() {
	BankAccount B;
	cout<<B.get_balance()<<endl;
	B.Deposit(1000);
	cout<<B.get_balance()<<endl;
	B.Withdraw(1001);
	cout<<B.get_balance()<<endl;
    return 0;
}