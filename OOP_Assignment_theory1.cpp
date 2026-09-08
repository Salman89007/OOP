#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter N"<<endl;
    cin>>n;
    char name[] = "salman";
    int * number = new int[n*n];
    int ** ptr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        ptr[i] = new int[number[num]];
    }
    delete[] number;
    for (int i = 0; i < n; i++)
    {
        delete[] ptr[number[i]];
    }
    delete[] ptr;
    
    return 0;
}