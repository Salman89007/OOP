#include <iostream>
using namespace std;

class Counter {
    static int count;
public:
    Counter()  { count++; }
    ~Counter() { count--; }
    static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
    cout << "Before any object: " << Counter::getCount() << endl;

    Counter c1, c2;
    cout << "After c1, c2:      " << Counter::getCount() << endl; 

    {
        Counter c3, c4, c5;
        cout << "Inside nested {}:  " << Counter::getCount() << endl; 
    } 

    cout << "After nested {}:   " << Counter::getCount() << endl; 

    Counter* p = new Counter();
    cout << "After new:         " << Counter::getCount() << endl; 

    delete p;
    cout << "After delete:      " << Counter::getCount() << endl;

    return 0; 
}