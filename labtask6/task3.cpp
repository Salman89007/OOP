#include <iostream>
#include <string>
using namespace std;
class Circle
{
private:
    double radius;
    bool validateRadius(double R)
    {
        if (R > 0)
        {
            return true;
        }
        return false;
    }

public:
    void setRadius(double R)
    {
        if (validateRadius(R))
        {
            radius = R;
        }else{
            cout<<"Invalid radius, radius is less than 1! "<<endl;
        }
    }
    double CalculateArea();
    double CalculatePerimeter();
};
double Circle::CalculateArea()
{
    return 3.1459 * (radius * radius);
}
double Circle::CalculatePerimeter()
{
    return 2 * 3.1459 * radius;
}
int main()
{
    Circle C;
    C.setRadius(5);

    cout << "AREA : " << C.CalculateArea() << endl;
    cout << "PERIMETER : " << C.CalculatePerimeter();

    return 0;
}