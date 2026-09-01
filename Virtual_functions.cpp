#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Some animal sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Woof" << endl;
    }
};

int main()
{
    Animal *a = new Dog();
    a->speak(); 
    return 0;
}