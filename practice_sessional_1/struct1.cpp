#include <iostream>
using namespace std;
struct Engine
{
    int hp;
    float cc;
};
struct Car
{
    string model;
    Engine eng;
};

int main()
{
    Car c[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "enter model for car " << i + 1 << " : " << endl;
        cin >> c[i].model;
        cout << "enter engine size for car " << i + 1 << " : " << endl;
        cin >> c[i].eng.cc;
        cout << "enter horsepower for car " << i + 1 << " : " << endl;
        cin >> c[i].eng.hp;
    }

    for (int i = 0; i < 3; i++)
    {
        if (c[i].eng.hp > 150)
        {
            cout << "printing " << endl;
            cout << c[i].model << " ";
            cout << c[i].eng.cc << " ";
            cout << c[i].eng.hp << " ";
        }
    }

    return 0;
}