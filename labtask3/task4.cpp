#include <iostream>
using namespace std;
void Fillarray(int *arr, int row, int col)
{
    cout << "enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i * col + j];
        }
    }
}
void printFlattened2D(int *arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i * cols + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cout << "enter rows : " << endl;
    cin >> m;
    cout << "enter columns : " << endl;
    cin >> n;
    int *arr = new int[m * n];
    Fillarray(arr, m, n);
    printFlattened2D(arr, m, n);
    delete[] arr;

    return 0;
}
