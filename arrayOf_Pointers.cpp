#include <iostream>
using namespace std;
int *boldMatrixSum(int arr[][3], int rows, int cols)
{
    int sum = 0;
    int sumDiagonal = 0;
    int sumAntiDiagonal = 0;

    int *ptr = new int[3];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        sumDiagonal += arr[i][i];
    }
    for (int i = 0; i < rows; i++)
    {
        sumAntiDiagonal += arr[i][cols-1-i];
    }
    ptr[0] = sum;
    ptr[1] = sumDiagonal;
    ptr[2] = sumAntiDiagonal;

    return ptr;
}

int main()
{
    int arr[3][3];

    int *sum = boldMatrixSum(arr, 3, 3);
    cout << "sum of all elements is : " << sum[0] << endl;
    cout << "sum of diagonal elements is : " << sum[1] << endl;
    cout << "sum of antidiagonal elements is : " << sum[2] << endl;
    return 0;
}