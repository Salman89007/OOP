#include <iostream>
using namespace std;

void Diagonal_sum(int (*arr)[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+= arr[i][i];
    }
    cout<<"sum is : "<<sum;
}

int main()
{
    int arr[3][3];
    cout<<"enter elements"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    Diagonal_sum(arr);

    return 0;
}