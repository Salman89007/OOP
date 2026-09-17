#include <iostream>
using namespace std;

int* resize(int *arr, int oldSize, int newSize){

    int * ptr = new int[newSize];
    int size;

    if (oldSize<newSize)
    {
        size = oldSize;
    }else{
        size = newSize;
    }
    for (int i = 0; i < size; i++)
    {
        ptr[i] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    
    delete[] arr;

    return ptr;
}

int main()
{
    int oldSize,newSize;
    cout<<"enter oldSize : "<<endl;
    cin>>oldSize;

    cout<<"enter newSize : "<<endl;
    cin>>newSize;

    int *ptr = new int[oldSize];

    for (int i = 0; i < oldSize; i++)
    {
        cin>>ptr[i];
    }
    cout<<"before size change : "<<endl;
    for (int i = 0; i < oldSize; i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    
    int * arr = resize(ptr,oldSize,newSize);
    cout<<"Freeing memory ...";

    delete[] arr;
    return 0;
}