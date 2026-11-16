#include <iostream>
using namespace std;

class A{
    protected:
    int x;
    public:
    A(int x):x(x){
        cout<<"A constructor created"<<endl;
    }
    virtual void show(){
        cout<<"not pure virtual though"<<endl;
    }
    virtual ~A(){
        cout<<"A constructor deleted"<<endl;
    };
};
class B : virtual public A{
    public:
    int y;
    B(int x , int y) : A(x),y(y){
        cout<<"B constructor created"<<endl;
    }
    void show()override{
        cout<<"Y : "<<y<<endl;
    }
    ~B(){
        cout<<"B constructor deleted"<<endl;
    } 
};
class C : virtual public A{
    public:
    int Z;
    C(int x , int Z) : A(x),Z(Z){
        cout<<"C constructor created"<<endl;
    }
    void show()override{
        cout<<"Z : "<<Z<<endl;
    }
    ~C(){
        cout<<"C constructor deleted"<<endl;
    } 
};
class D : public B,  public C{
    public:
    int Z;
    D(int x , int Z) : C(x,Z),B(x,Z),A(x),Z(Z){
        cout<<"D constructor created"<<endl;
    }
    void show()override{
        cout<<"Z : "<<Z<<endl;
    }
    ~D(){
        cout<<"D constructor deleted"<<endl;
    }
};

int main() {
    D d(1,2);
    d.show();
    d.B::show();
    d.A::show();
    d.C::show();
    return 0;
}