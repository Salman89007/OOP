#include<iostream>
using namespace std;

class rectangle{
    private:
    int len, width;
    int *ptr;
    public:
    rectangle(){
        len = 1;
        width = 2;
        ptr = new int(3);
    }
    void setter(int val){
        delete ptr;
        ptr = new int(val);
    }
    rectangle(rectangle &R){ //this is copy constructor
        len = R.len;
        width = R.width;
        ptr = new int(*R.ptr);
    }
    void display(){
        cout<<"length : "<<len<<endl;
        cout<<"width : "<<width<<endl;
        cout<<"ptr value  : "<<*ptr<<endl;
    }
    ~rectangle(){
        delete ptr;
        cout<<"memory and class deleted"<<endl;
    }
};
int main(){
    rectangle R1;
    rectangle R2 = R1;
    R1.display();
    R1.setter(10); //default is 3
    R1.display();
    R2.display();

    return 0;
}