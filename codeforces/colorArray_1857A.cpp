#include <iostream>
using namespace std;
int main()
{
    int n, k; // n is basically how many tests and k is number of elements
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int arr[k];
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            cin >> arr[j];
            sum += arr[j];
        }
        if (sum % 2 == 0 && k >= 2)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}