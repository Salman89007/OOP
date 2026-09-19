#include <iostream>
using namespace std;

struct Inner
{
    int a, b;
};
struct Outer
{
    int id;
    Inner in;
};

int main()
{
    Outer * o = new Outer[3];
    for (int i = 0; i < 3; i++)
    {
        o[i].id = i+1;
        o[i].in.a = i+1*2;
        o[i].in.b = i+1*3;
        
    }

    for (int i = 0; i < 3; i++)
    {
        cout<<o[i].id<<" ";
        cout<<o[i].in.a <<" ";
        cout<<o[i].in.b<<" ";
        cout<<endl;
    }

    delete[] o;
    return 0;
}