#include <iostream>
using namespace std;

int** construct2DArray(int* original, int m, int n){

}

int main() {
    int m, n;

    cout << "enter rows : ";
    cin >> m;

    cout << "enter columns : ";
    cin >> n;
    
    int arr[m*n];
    cout<<"enter elements for 1D array : "<<endl;
    for (int i = 0; i < m*n; i++)
    {
        cin>>arr[i];
    }
    int** ptr = new int*[m];
    for (int i = 0; i < m; i++)
    {
        ptr[i] = new int[n];
    }
    
    for (int i = 0; i < m; i++)
    {
        delete[] ptr[i];
    }
    delete ptr;
    
    return 0;
}