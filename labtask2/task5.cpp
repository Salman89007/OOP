#include <iostream>
using namespace std;

void Fillarray(int **ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> ptr[i][j];
        }
    }
}

void Print(int **ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int size;

    cout << "enter size of X grid : ";
    cin >> size;

    int **ptr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = new int[size];
    }

    Fillarray(ptr, size);
    Print(ptr, size);

    for (int i = 0; i < size; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}