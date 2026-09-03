#include <iostream>
using namespace std;

class Base{
    int *x;
    public:
    Base(int val){
        x = new int(val);
    }
    Base(const Base& b){
        x = new int(*b.x);
    }
    void setVal(int val){
        

    }


};

int main() {
    Base b1(10);
    Base b2 = b1;//same as Base b2(b1)
    
    return 0;
}