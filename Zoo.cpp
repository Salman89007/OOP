#include <iostream>
#include <string>
using namespace std;

class Animal
{
    string name;
    static int totalAnimals;

public:
    Animal(string name)
    {
        this->name = name;
        totalAnimals++;
    }
    virtual void speak() = 0;
    virtual ~Animal() {}
};
class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Dogs section" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "Cats section" << endl;
    }
};
class Zoo
{
    Animal **A;
    int capacity;
    int count;

public:
    Zoo(int capacity) : capacity(capacity), count(0)
    {
        A = new Animal *[this->capacity];
    }
    void addAnimal(Animal *a)
    {
        if (count == capacity)
        {
            Animal **temp = new Animal *[capacity];
            for (int i = 0; i < count; i++)
                temp[i] = A[i];
            delete[] temp;
            A = temp;
        }
        A[count++] = a;
    }
    void showAll()
    {
        for (int i = 0; i < count; i++)
        {
            A[i]->speak();
        }
    }
    ~Zoo()
    {
        for (int i = 0; i < count; i++)
        {
            delete[] A[i];
        }
        delete A;
    }
};
int Animal::totalAnimals = 0;

int main()
{
    Zoo z(2);
    z.addAnimal(new Dog("Rex"));
    z.addAnimal(new Cat("Tom"));
    z.addAnimal(new Dog("Max")); // triggers growth
    z.showAll();

    return 0;
}