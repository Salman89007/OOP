#include <iostream>
using namespace std;

void Fillarray(int **ptr,int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>ptr[i][j];
        }   
    }

}

void Print(int **ptr,int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<ptr[i][j]<<" ";
        }   
        cout<<endl;
    }

}

int main() {
    int row,col;

    cout<<"enter rows : ";
    cin>>row;

    cout<<"enter columns : ";
    cin>>col;

    int** ptr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        ptr[i] = new int[col];
    }
    
    Fillarray(ptr,row,col);
    Print(ptr,row,col);

    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}