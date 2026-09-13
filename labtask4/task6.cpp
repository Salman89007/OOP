#include <iostream>
using namespace std;

int* mergeArrays(int *arr1, int size1, int *arr2, int size2){

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

    // freeing
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}