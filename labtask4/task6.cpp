#include <iostream>
using namespace std;

int* mergeArrays(int *arr1, int size1, int *arr2, int size2){
    int * arr = new int[size1+size2];
    for (int i = 0; i < size1; i++)
    {
        arr[i] = arr1[i];
    }
    for (int i = size1; i < size1+size2; i++)
    {
        arr[i] = arr2[i - size1];
    }
    return arr;
}

int main()
{
    int size1,size2;
    cout<<"Enter size1 : "<<endl;
    cin>>size1;
    int *arr1 = new int[size1];

    cout<<"Enter size2 : "<<endl;
    cin>>size2;
    int *arr2 = new int[size2];

    cout<<"enter elements of arr1 : "<<endl;
    for (int i = 0; i < size1; i++)
    {
        cin>>arr1[i];
    }

    cout<<"enter elements of arr2 : "<<endl;
    for (int i = 0; i < size2; i++)
    {
        cin>>arr2[i];
    }
    int * merge = mergeArrays(arr1,size1,arr2,size2);
    for (int i = 0; i < size1+size2; i++)
    {
        cout<<merge[i]<<" ";
    }
    delete[] arr1;
    delete[] arr2;
    delete[] merge;
    return 0;
}