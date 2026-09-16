#include <iostream>
using namespace std;

void Insert_Print(int **ptr,int rows,int *cols){

    //inserting data

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cin>>ptr[i][j];
        }
    }

    //printing

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main() {
    int rows;
    cout << "enter rows : ";
    cin >> rows;

    int arr[rows];
    int ** ptr = new int*[rows];
    //allocation
    for (int i = 0; i < rows; i++)
    {
        cout<<"enter cols for row "<<i+1<<" : ";
        cin>>arr[i];
        ptr[i] = new int[arr[i]];
    }

    Insert_Print(ptr,rows,arr);

    return 0;
}