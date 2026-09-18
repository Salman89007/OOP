#include <iostream>
using namespace std;

int main()
{
    int **ptr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int[3];
    }

    int **arr = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> ptr[i][j];
            arr[i][j] = ptr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    for (int i = 0; i < 3; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}