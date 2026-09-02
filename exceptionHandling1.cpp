#include <iostream>
using namespace std;

int divide(int a, int b)
{
    if (b == 0)
        throw "Division by zero!";   // throwing a simple string (can throw other types too)
    return a / b;
}

int main()
{
    try
    {
        cout << divide(10, 2) << endl;   // works fine, prints 5
        cout << divide(5, 0) << endl;    // this line throws
        cout << "This line never runs" << endl;
    }
    catch (const char *msg)              // catches the thrown string
    {
        cout << "Error: " << msg << endl;
    }

    cout << "Program continues normally after catch" << endl;

    return 0;
}