#include <iostream>
#include <string>
using namespace std;
class Item{
	private:
	double price;
	int quantity;
	public:
	Item(double Price,int Quantity){
		price =  Price;
		quantity = Quantity;
	}
	~Item()
	{
		cout<<"constructor destroyed"<<endl;
	}
};

int main(){
	Item I[3];
	I[0] (100,5);
	I[1] (200,10);
	I[2] (300,15);
	
	return 0;
}