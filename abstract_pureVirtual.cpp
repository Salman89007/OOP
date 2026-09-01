#include <iostream>
using namespace std;

class base{
    protected:
    int x;int y;
    public:
    base(int x, int y){
        this->x = x;
        this->y = y;
    }
    virtual void showFunc() = 0;

};
class derived : public base{
    protected:
    int x,y;
    int z;
    public:
    derived(int x,int y,int z):base(x,y){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main() {


    
    return 0;
}