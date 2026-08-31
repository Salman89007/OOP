#include <iostream>
using namespace std;

int diagonalSum(int** matrix,int size){
    int sum = 0;
    return sum;
}

void Print(int sum)
{
    cout << "sum is " << sum;
}

int main() {
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

    int sum = diagonalSum(ptr,row*col);







    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    
    return 0;
}