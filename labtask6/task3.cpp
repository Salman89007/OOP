#include <iostream>
#include <string>
using namespace std;
class Circle{
    private:
    double radius;
    bool validateRadius(){
    	if(radius>0){
    		return true;
		}
    	return false;
	}
	public:
	void setRadius(double R)
	{
    	radius = R;
    }
	void CalculateArea(double R);
	void CalculatePerimeter(double R);
};
void Circle::CalculateArea(double R){
	return 3.1459 * (R*R);
}
void Circle::CalculatePerimeter(double R){
	return 2*(R*R);
}
int main() {
	Circle C;
	C.setRadius(1);
	C.CalculateArea();
	C.CalculatePerimeter();

    return 0;
}