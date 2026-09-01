#include <iostream>
using namespace std;

class base{
    protected:
    int x;
    int y;
    public:
    base(int x, int y){
        this->x = x;
        this->y = y;
    }
    virtual void showFunc() = 0;

};
class derived1 : public base{
    protected:
    int z;
    public:
    derived1(int x,int y,int z):base(x,y){
        this->z = z;
    }
    void showFunc() override{
        cout<<"derived1"<<endl;
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<z<<endl;
    }
};
class derived2 : public base{
    protected:
    int z;
    public:
    derived2(int x,int y,int z):base(x,y){
        this->z = z;
    }
    void showFunc() override{
        cout<<"derived2"<<endl;
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<z<<endl;
    }
};

int main() {
    base * ptr1 = new derived1(1,2,3);
    ptr1->showFunc();

    base * ptr2 = new derived2(4,5,6);
    ptr2->showFunc();

    delete ptr1;
    delete ptr2;

    return 0;
}