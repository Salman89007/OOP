#include <iostream>
using namespace std;

class Point{
	int x,y;
	public:
	Point(int x,int y){
		this->x = x;
		this->y = y;
	}
	void Display(){
		cout<<"x : "<<this->x<<endl;
		cout<<"y : "<<this->y<<endl;
	}
};

int main(){
	Point P1(1,2);
	P1.Display();
	
	
	return 0;
}