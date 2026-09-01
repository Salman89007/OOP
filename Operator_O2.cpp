#include <iostream>
using namespace std;

class base
{
    int x;
    int y;

public:
    base()
    {
        x = 0;
        y = 0;
    }
    base(int x, int y)
    {                 
        this->x = x;  
        this->y = y;  
    }
    base operator-(base &b){
        base result;        
        result.x = b.x - x; 
        result.y = b.y - y; 
        return result;      
    }                      
                            
    void print()            
    {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;  

    }
    ~base(){
        cout<<"operator deleted"<<endl;
    }
};

int main()
{
    base b1(1, 2);
    base b2(4, 3);
    base result = b1-b2;
    result.print();

    return 0;
}