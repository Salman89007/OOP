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

int countNegatives(int **grid, int rows, int columns)
{
    int neg = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] < 0)
            {
                neg++;
            }
        }
    }
    return neg;
}

void Print(int neg){
    cout<<neg<<endl;
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
    Fillarray(ptr,row,col);
    int negativeNums = countNegatives(ptr, row, col);
    Print(negativeNums);

    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}