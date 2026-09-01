#include <iostream>
using namespace std;

class base
{
    int sum1;
    int sum2;
    int x;
    int y;

public:
    base()
    {
        sum1 = 0;
        sum2 = 0;
    }

    base(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    base add(base &b)
    {
        base result;
        result.x = b.x + x;
        result.y = b.y + y;
        return result;
    }
    void print()
    {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
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