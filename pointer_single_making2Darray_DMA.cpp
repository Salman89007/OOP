/*
here basically I'm gonna write a code in which ill be making a 2D array dynamically
using single pointer;
*/
#include <iostream>
using namespace std;

void Fillarray(int *ptr,int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>ptr[i*col+j];
        }   
    }

}

void Print(int *ptr,int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<ptr[i*col+j]<<" ";
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

    int * ptr = new int[row*col];

    Fillarray(ptr,row,col);
    Print(ptr,row,col);

    delete[] ptr;

    return 0;
}