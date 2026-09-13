#include <iostream>
using namespace std;

int Max_element(int **ptr, int rows, int *cols)
{
    int max = ptr[0][cols[0]];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            if (ptr[i][j > max])
            {
                max = ptr[i][j];
            }
        }
    }
    return max;
}

int main()
{
    int rows;
    cout << "ROWS : " << endl;
    cin >> rows;

    int *cols = new int[rows];

    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "enter cols for row" << i + 1 << " : " << endl;
        cin >> cols[i];
        arr[i] = new int[cols[i]];
    }
    // filling
    cout << "enter elements : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << "arr " << i + 1 << " " << j + 1 << endl;
            cin >> arr[i][j];
        }
    }
    cout << "MAX element is " << Max_element(arr, rows, cols) << endl;
    // freeing
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}