#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][3];
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
        int sum = arr[i][0] + arr[i][1] + arr[i][2];
        if (sum >= 2)
        {
            count++;
        }
    }
    cout << "count = " << count;
    return 0;
}