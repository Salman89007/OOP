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
    base(int x, int y)//for b1 1 2 gets stored
    {                 //for b2 4 and 3 gets stored , remember
        this->x = x;  //they have different memory assigned for each class made
        this->y = y;  
    }
    base operator+(base &b){//now comes base b, here we are doing b1+2
        base result;        //which means b1.operator+(b2)
        result.x = b.x + x; //this means b1 class is called and passing b2 into
        result.y = b.y + y; //base &b so we can access b2 via b.
        return result;      //now result is created (which has its own members all of it)
    }                       //result x and y are empty(default constructor)
                            //so we are storing x of b1 and of b2 via b.x and store it in
    void print()            //result's x and y 
    {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;   
    }
};

int main()
{
    base b1(1, 2);
    base b2(4, 3);
    base result = b1+b2;
    result.print();

    return 0;
}