#include <iostream>
using namespace std;

int main() {
    int * arr1 = new int[3];
    arr1[0] = 1;
    arr1[0] = 2;
    arr1[0] = 3;
    //or via loop
    for (int i = 0; i < 3; i++)
    {
        cin>>arr1[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<arr1[i]<<" ";
    }

    int ** arr2 = new int* [2];//here 2 are rows
    arr2[0] = new int[3]{1,2,3};//here 3 are columns

    
    return 0;
}