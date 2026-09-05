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
int* addFlattened2D(int* arr1, int* arr2, int* arr3, int rows, int cols)
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr3[i * cols + j] += arr1[i * cols + j] + arr2[i * cols + j];
        }
    }
    return arr3;
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

    int *arr1 = new int[m * n];
    int *arr2 = new int[m * n];
    int *arr3 = new int[m * n];

    Fillarray(arr1, m, n);
    Fillarray(arr2, m, n);

    int * sum = addFlattened2D(arr1, arr2, arr3, m, n);
    cout<<"sum is "<<*sum;

    printFlattened2D(arr1, m, n);
    printFlattened2D(arr2, m, n);
    printFlattened2D(arr3, m, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
