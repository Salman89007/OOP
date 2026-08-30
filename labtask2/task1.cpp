#include <iostream>
using namespace std;

void Fillarray(int **ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ptr[i][j];
        }
    }
}

int findlargest(int **matrix, int rows, int columns)
{
}

int main()
{
    int row, col;

    cout << "enter rows : ";
    cin >> row;

    cout << "enter columns : ";
    cin >> col;

    int **ptr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr[i] = new int[col];
    }

    return 0;
}