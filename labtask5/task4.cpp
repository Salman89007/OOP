#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

double Distance(Point P1, Point P2)
{
    double val = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
    return val;
}
Point returnPoint(Point P1, Point P2)
{
    Point m;
    m.x = (P1.x + P2.x) / 2;
    m.y = (P1.y + P2.y) / 2;
    return m;
}
int main()
{
    Point P1, P2;
    cout << "enter P1.x and P1.y : ";
    cin >> P1.x >> P1.y;

    cout << "enter P2.x and P2.y : ";
    cin >> P2.x >> P2.y;

    cout << "Distance is : " << Distance(P1, P2) << endl;
    Point M = returnPoint(P1,P2);
    cout<<"point m.x is : "<<M.x<<" point m.y is : "<<M.y;

    return 0;
}