#include <iostream>
using namespace std;

void Fillarray(int **ptr, int row, int col)
{
    cout << "enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ptr[i][j];
        }
    }
}

int **transposeMatrix(int **arr, int rows, int cols)
{
    int **transpose = new int *[cols];
    for (int i = 0; i < cols; i++)
    {
        transpose[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }

    return transpose;
}

void Print(int **arr, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;
    cout << "enter rows : " << endl;
    cin >> rows;

    cout << "enter cols : " << endl;
    cin >> cols;

    int **ptr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }

    Fillarray(ptr, rows, cols);
    cout << "Before Transpose" << endl;
    Print(ptr, rows, cols);

    int  ** transpose = transposeMatrix(ptr, rows, cols);
    cout << "After Transpose" << endl;
    Print(transpose, cols, rows);

    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    for (int i = 0; i < cols; i++)
    {
        delete[] transpose[i];
    }
    delete[] transpose;

    return 0;
}