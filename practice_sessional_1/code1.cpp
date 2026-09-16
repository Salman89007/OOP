#include <iostream>
using namespace std;

int *create2D(int rows, int cols)
{
    int *ptr = new int[rows * cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> ptr[i * cols + j];
        }
    }
    return ptr;
}
void free2D(int *arr)
{
    delete[] arr;
}

int main()
{

    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;

    cout << "enter cols : ";
    cin >> cols;

    int *ptr = create2D(rows, cols);
    free2D(ptr);

    return 0;
}