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
double* calculateRowAverages(int** arr, int rows, int cols, double*rowAverages)
{
    double sum = 0;
    rowAverages = &sum;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rowAverages += arr[i][j];
        }
        
    }
    

    return rowAverages;
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

    cout << "enter cols (same number as rows for square matrix): " << endl;
    cin >> cols;

    int **ptr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }
    double *rowAvg = new double[rows*cols];

    Fillarray(ptr, rows, cols);
    double* Avg = calculateRowAverages(ptr, rows, cols,rowAvg);
    Print(ptr, rows, cols);



    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;



    return 0;
}