#include <iostream>
#include <string>
using namespace std;

int main() {
    int **ptr = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>ptr[i][j];
        }

    }
    int **shallow = ptr;
    shallow[0][0] = 99;
    cout<<ptr[0][0]<<endl;

    for (int i = 0; i < 3; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    shallow = nullptr;
    ptr = nullptr;
    return 0;
}