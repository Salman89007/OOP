#include <iostream>
using namespace std;

class base
{
    int x;
    int y;

public:
    base() {}
    base(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    base operator-(base &b)
    {
        base result;
        result.x = x - b.x;
        result.y = y - b.y;
        return result;
    }

    bool operator==(base &b)
    {
        return (x == b.x && y == b.y);
    }

    // needs to be a "friend" since left side isn't a base object (it's cout)
    friend ostream &operator<<(ostream &out, base &b)
    {
        out << "(" << b.x << ", " << b.y << ")";
        return out;
    }
};

int main()
{
    base b1(5, 8);
    base b2(2, 3);

    base result = b1 - b2;   // calls operator-
    cout << result << endl;  // calls operator

    if (b1 == b2)             // calls operator==
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    return 0;
}