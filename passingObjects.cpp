#include <iostream>
using namespace std;

class base
{
    int x;
    int y;

public:
    base()
    {
    }
    base(int x, int y)
    {
        this->x = x;//1 2 stored
        this->y = y;
    }
    base add(base &b)//b.x means b2's values e.g 4 and 3
    {
        base result;
        result.x = b.x + x;//4+1 // now result x stores 5
        result.y = b.y + y;//3+2 //same y stores 5
        return result;
    }
    void print()
    {
        cout << "x : " << x << endl;   //when called by result , members
        cout << "y : " << y << endl;   // x and y  are there 5,5
    }
};

int main()
{
    base b1(1, 2);
    base b2(4, 3);

    base result = b1.add(b2);
    result.print();

    return 0;
}