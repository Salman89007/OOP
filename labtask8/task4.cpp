#include <iostream>
using namespace std;

class Fraction{
	const double numerator;
	const double denominator;
	public:
	Fraction(const double numerator, const double denominator) : numerator(numerator),denominator(denominator){}
	const double getValue() const{
		return numerator/denominator;
	}
};

int main(){
	double x,y;
	
	cout<<"enter x : ";
	cin>>x;
	cout<<"enter y : ";
	cin>>y;
	
	Fraction F(x,y);
	cout<<"Fraction value is : "<<F.getValue();

	return 0;
}