#include <iostream>
using namespace std;
void Fillarray(int arr[][4], int row, int col)
{
    cout << "enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}
bool isSymmetric(int arr[][4], int rows, int cols)
{
    bool sym = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == arr[j][i])
            {
                sym = true;
            }
        }
    }
    return sym;
}
int main()
{
    int m, n;
    cout << "enter rows : " << endl;
    cin >> m;
    cout << "enter columns : " << endl;
    cin >> n;
    int arr[m][n];
    Fillarray(arr, m, n);
    bool sym = isSymmetric(arr, m, n);
    if (sym)
    {
        cout << "array is symmetric" << endl;
    }
    else
    {
        cout << "array is not symmetric" << endl;
    }
    return 0;
}
