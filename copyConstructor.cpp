#include <iostream>
using namespace std;

class Base{
    int *x;
    public:
    Base(int val){
        x = new int(val);
    }

    Base(const Base& b){       //copy constructor
        x = new int(*b.x);     //b.x is basically b1.x which is a memory address
                               //* is for dereferencing meaning a value there
    }

    void setVal(int val){
        *x = val;
    }
    void Print(){
        cout<<"data is : "<<*x<<endl;
    }
};

int main() {
    Base b1(10);
    Base b2 = b1;//same as Base b2(b1)
    b2.setVal(99);
    b1.Print();
    b2.Print();
    return 0;
}