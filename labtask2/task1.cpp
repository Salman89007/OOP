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

int* findlargest(int **matrix, int rows, int columns)
{
    int *ptr = *matrix;
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (ptr[i * columns + j] > max)
            {
                max = ptr[i * columns + j];
            }
        }
    }

    return *matrix;
}

void Print(int *max){
    cout<<"max element is "<<*max;
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
    int* max = findlargest(ptr,row,col);
    Print(max);

    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}