#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout<<"a is "<<*a<<endl;
    cout<<"b is "<<*b<<endl;
}

void swapPtr(int **a, int **b)
{
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;

    cout<<"a is "<<**a<<endl;
    cout<<"b is "<<**b<<endl;
}

int main()
{
    int a, b;
    int *A = &a;
    int *B = &b;

    cout << "enter a : ";
    cin >> a;

    cout << "enter b : ";
    cin >> b;

    swap(&a, &b);
    swapPtr(&A, &B);

    return 0;
}