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

int** transposeMatrix(int** arr, int rows, int cols){


    return arr;
}

void Print(int** arr, int rows, int cols){
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows,cols;
    cout<<"enter rows : "<<endl;
    cin>>rows;

    cout<<"enter rows : "<<endl;
    cin>>rows;

    int **ptr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }

    Fillarray(ptr,rows,cols);
    transposeMatrix(ptr,rows,cols);
    
    return 0;
}