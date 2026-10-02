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
	void Display(){
	    cout<<"Price "<<price<<endl;
	    cout<<"Quantity "<<quantity<<endl;
	}
	~Item()
	{
		cout<<"constructor destroyed"<<endl;
	}
};

int main(){
	Item I[3] = {Item(100,5),Item(200,10),Item(300,2) };
	
	for(int i=0; i<3; i++){
	    cout<<"Item :"<<i+1<<endl;
	    I[i].Display();
	}
	return 0;
}