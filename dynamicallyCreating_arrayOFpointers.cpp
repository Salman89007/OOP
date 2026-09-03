#include <iostream>
using namespace std;

int main() {
    int **arr = new int*[5];
    //here we have int* arr[5];
    //this can store 5 ints
    arr[0] = new int[5];
    arr[1] = new int[5];
    arr[2] = new int[5];
    arr[3] = new int[5];
    arr[4] = new int[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        
    }

    return 0;
}