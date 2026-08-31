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

int diagonalSum(int** matrix,int size){
    int sum = 0;
    return sum;
}

void Print(int sum)
{
    cout << "sum is " << sum;
}

int main() {
    int row, col;

    cout << "enter rows : ";
    cin >> row;

    cout << "enter columns (must be equal to row) : ";
    cin >> col;

    int **ptr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr[i] = new int[col];
    }

    Fillarray(ptr,row,col);
    int sum = diagonalSum(ptr,row);
    Print(sum);

    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    
    return 0;
}