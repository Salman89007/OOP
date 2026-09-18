#include <iostream>
using namespace std;

struct Point
{
    int x = 1, y = 2;
};
void movePoint(Point *p, int dx, int dy)
{ 
    Point point;
    p->x = dx;
    p->y = dy;
    cout<<p->x<<" "<<p->y;
}

int main()
{
    Point p;
    Point * ptr = &p;
    movePoint(ptr,3,4);

    return 0;
}