#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter N" << endl;
    cin >> n;
    char name[] = "salman";
    int *number = new int[n];
    int **ptr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int cols;
        cin >> cols;
        ptr[i] = new int[number[cols]];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter for ptr[" << i << "]" << "[" << j << "]" <<endl;
            cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "ptr[" << i << "]" << "[" << j << "]" <<" "<<endl;
            cout << ptr[i][j];
        }
        cout<<endl;
    }

    delete[] number;
    for (int i = 0; i < n; i++)
    {
        delete[] ptr[number[i]];
    }
    delete[] ptr;

    return 0;
}