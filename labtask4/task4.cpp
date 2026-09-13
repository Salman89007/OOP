#include <iostream>
using namespace std;

int* Rows_Sum(int **ptr,int rows,int cols){
    int* rowSum = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += ptr[i][j];
            rowSum[i] = sum;
        }
    }
    return rowSum;
}

int main()
{
    int rows, cols;
    cout << "ROWS : " << endl;
    cin >> rows;

    cout << "COLS : " << endl;
    cin >> cols;

    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    //filling
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>arr[i][j];
        }
    }
    //calling function
    int * rowSum = Rows_Sum(arr,rows,cols);
    for (int i = 0; i < rows; i++)
    {
        cout<<"ROW "<<i+1<<" sum is : "<<rowSum[i]<<endl;
    }
    //freeing memory
    
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] rowSum;
    return 0;
}