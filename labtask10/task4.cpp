#include <iostream>
using namespace std;

class LoanAccount;

class SavingsAccount{
	private:
	double balance;
	public:
	SavingsAccount(double balance) : balance(balance){
	}
	friend void auditCustomerRisk(SavingsAccount& s, LoanAccount& l);
	virtual ~SavingsAccount(){
	}
};

class LoanAccount{
	private:
	double loanAmount;
	int missedPayments;
	public:
	LoanAccount(double loanAmount, int missedPayments) : loanAmount(loanAmount), missedPayments(missedPayments){
	}
	friend void auditCustomerRisk(SavingsAccount& s, LoanAccount& l);
	virtual ~LoanAccount(){
	}
};

void auditCustomerRisk(SavingsAccount& s, LoanAccount& l){
	int score = 700;
	if(l.loanAmount > s.balance){
		score -= 100;
	}
	score -= l.missedPayments * 50;
	if(s.balance > 100000){
		score += 50;
	}
	cout<<"Savings balance : "<<s.balance<<endl;
	cout<<"Loan amount : "<<l.loanAmount<<endl;
	cout<<"Missed payments : "<<l.missedPayments<<endl;
	cout<<"Credit score : "<<score<<endl;
	if(score >= 650){
		cout<<"Risk : Low"<<endl;
	}
	else if(score >= 500){
		cout<<"Risk : Medium"<<endl;
	}
	else{
		cout<<"Risk : High"<<endl;
	}
}

int main(){
	SavingsAccount s(150000);
	LoanAccount l(200000, 2);
	auditCustomerRisk(s, l);
	return 0;
}