#include <iostream>
using namespace std;

int main()
{
    int m[5][5];
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (m[3][3] != 1)
            {
            
            }
        }
    }

    return 0;
}