#include <iostream>
using namespace std;

int FindMin(int *arr, int size){
    int Min = *(arr + 0);
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i)<Min)
        {
            Min = *(arr + i);
        }
    }
    return Min;
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
    
    cout<<"MIN number is : "<<FindMin(arr,size)<<endl;
    return 0;
}