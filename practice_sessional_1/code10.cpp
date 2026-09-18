#include <iostream>
using namespace std;

int main() {
    //jagged 2D array dynamically
    int arr[3];
    int ** ptr = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        cin>>arr[i];
        ptr[i] = new int[arr[i]];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            ptr[i][j] = i*10+j;
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for (int i = 0; i < 3; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    
    return 0;
}