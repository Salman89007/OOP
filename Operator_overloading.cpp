#include <iostream>
using namespace std;

class base
{
protected:
    int sum1 = 0;
    int sum2 = 0;
    int x;
    int y;

public:
    base(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int add(base &b)
    {
        return sum1 = b.x + x;
        return sum2 = b.y + y;
    }
    void print(const base &b)
    {
        cout << sum1;
        cout << sum2;
    }
};

class derived : public base
{
};

int main()
{
    base b(1, 2);
    b.add(b);
    b.print(b);

    return 0;
}