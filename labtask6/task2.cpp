#include <iostream>
#include <string>
using namespace std;
class Class{
    private:
    double radius;
    public:
    void setRadius(double R)
	{
    	radius = R;
    }
    double getArea() const {
    	return 3.1459 * (radius*radius);
	}
};
int main() {
	Class C;
	C.setRadius(1);
	cout<<"Area is : "<<C.getArea();

    return 0;
}