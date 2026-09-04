#include <iostream>
using namespace std;
int** boldMatrixSum(int arr[][3], int rows, int cols){
    int sum = 0;
    int sumDiagonal = 0;
    int sumAntiDiagonal = 0;
    int *ptr[3] = {&sum,&sumDiagonal,&sumAntiDiagonal};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum+= arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sumDiagonal+= arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols ; j++)
        {
            sumAntiDiagonal+= arr[i][j];
        }
    }

    return ptr;
}

int main() {
    int arr[3][3];
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int** sum = boldMatrixSum(arr,3,3);
    cout<<"sum of all elements is : "<<*sum[0]<<endl;
    cout<<"sum of diagonal elements is : "<<*sum[1]<<endl;
    cout<<"sum of antidiagonal elements is : "<<*sum[2]<<endl;
    return 0;
}