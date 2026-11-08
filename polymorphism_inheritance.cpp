#include <iostream>
using namespace std;
class A{
    protected:
    string name;
    int model;
    public:
    A(string name,int model):name(name),model(model){}
    virtual void Display(){
        cout<<"name is "<<name<<endl;
        cout<<"model : "<<model<<endl;
    }
    virtual ~A(){}
};
class B : virtual public A{
    protected:
    int copiesSold;
    public:
    B(string name,int model,int copiesSold): A(name,model),copiesSold(copiesSold){}
    void Display() override{
        A::Display();
        cout<<"NUmber of copies sold : "<<copiesSold<<endl;
    }

};
class C : virtual public A{
    protected:
    int copiesSold;
    public:
    C(string name,int model,int copiesSold) : A(name,model),copiesSold(copiesSold){}
    void Display()override{
        A::Display();
        cout<<"NUmber of copies sold : "<<copiesSold<<endl;
    }
};
class D :  public B, public C{
    protected:
    double revenue;
    public:
    D(string name, int model,int copiesSold,double revenue): A(name,model),B(name,model,copiesSold),C(name,model,copiesSold),revenue(revenue){}
    void Display()override{
        A::Display();
        cout<<"NUmber of copies sold : "<<B::copiesSold<<endl;
        cout<<"NUmber of copies sold : "<<C::copiesSold<<endl;
        cout<<"Revenue : "<<revenue<<endl;
    }
};
int main(){
    A* a = new D("",1,1,1);
    a->Display();
    return 0;
}
