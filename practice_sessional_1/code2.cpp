#include <iostream>
using namespace std;

int** create2D(int rows, int cols){

    int ** ptr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>ptr[i][j];
        }
        
    }
    
    return ptr;

}
void free2D(int** arr, int rows){

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[rows];
    }
    delete[] arr;

}

int main() {

    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;

    cout << "enter cols : ";
    cin >> cols;

    int** ptr = create2D(rows,cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    free2D(ptr,rows);
    
    return 0;
}