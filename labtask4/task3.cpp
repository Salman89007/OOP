#include <iostream>
using namespace std;

int Count_Even(int *arr, int size){
    int Even = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 ==0)
        {
            Even++;
        }
    }
    return Even;
}

int main() {
    int size;
    cout<<"enter size"<<endl;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Even numbers : "<<Count_Even(arr,size)<<endl;
    return 0;
}