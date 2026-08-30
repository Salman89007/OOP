#include <iostream>
using namespace std;

int** construct2DArray(int* original, int m, int n){

    int** ptr = new int*[m];
    for (int i = 0; i < m; i++)
    {
        ptr[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ptr[i][j] = original[i*n+j];
        }
    }
    
    return ptr;
}

void Print(int** ptr, int m, int n){
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int m, n;

    cout << "enter rows : ";
    cin >> m;

    cout << "enter columns : ";
    cin >> n;
    
    int arr[m*n];
    cout<<"enter elements for 1D array : "<<endl;
    for (int i = 0; i < m*n; i++)
    {
        cin>>arr[i];
    }
    
    int **DoubleArray = construct2DArray(arr,m,n);
    Print(DoubleArray,m,n);

    for (int i = 0; i < m; i++)
    {
        delete[] DoubleArray[i];
    }
    delete DoubleArray;

    return 0;
}