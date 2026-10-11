#include <iostream>
using namespace std;
class Car{
	static int totalCars;
	public:
	Car(){
	    totalCars++;
	}
	static int returnCar(){
		return totalCars;
	}
	~Car(){totalCars--;}
};
int Car::totalCars = 0;
int main(){
	cout<<"before creating any object : "<<Car::returnCar()<<endl;
	Car C1,C2,C3;
	cout<<"after creating object : "<<Car::returnCar()<<endl;
	cout<<"after creating object : "<<C1.returnCar()<<endl;
	
	return 0;
}