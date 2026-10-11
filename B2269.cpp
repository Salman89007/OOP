#include <iostream>
using namespace std;
int returnSum(int k, int *arr)
{
    int Sum = 0;
    for (int j = 0; j < k; j++)
    {
        int x = arr[j];
        int sum = 0;
        while (x > 0)
        {
            int num = x % 10;
            sum += num * num;
            x = x / 10;
        }
        Sum = sum;
        cout << endl
             << "sum is " << sum;
    }
    return Sum;
}
int main()
{
    int n;
    cout << "enter n" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        int k;
        cout << "enter k" << endl;
        cin >> k;
        int arr[k];
        for (int j = 0; j < k; j++)
        {
            cin >> arr[j];
        }
        for (int j = 0; j < k; j++)
        {
            cout << endl
                 << arr[j] << " ";
        }
        int Sum = returnSum(k,arr);

        cout << endl;
    }

    return 0;
}