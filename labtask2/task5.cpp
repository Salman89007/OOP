#include <iostream>
using namespace std;

void Fillarray(int **ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> ptr[i][j];
        }
    }
}

int Count(int **ptr, int size)
{
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (ptr[i][j] == 1)
            {
                num++;
            }
        }
    }
    return num;
}

void Found(int **ptr, int size)
{
    int row, col;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "enter rows : ";
            cin >> row;

            cout << "enter columns : ";
            cin >> col;
            if (ptr[i][j] == ptr[row][col])
            {
                ptr[i][j] = 0;
            }
        }
    }
}
void printCount(int count){
    cout<<"enemies alive : "<<count<<endl;
}

void Print(int **ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int size;

    cout << "enter size of X grid : ";
    cin >> size;

    int **ptr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = new int[size];
    }

    Fillarray(ptr, size);
    int count = Count(ptr, size);
    printCount(count);
    Found(ptr, size);
    Print(ptr, size);

    for (int i = 0; i < size; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}