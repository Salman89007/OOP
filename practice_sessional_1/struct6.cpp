#include <iostream>
using namespace std;

int main()
{
    int choice;
    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;

    cout << "enter cols : ";
    cin >> cols;

    bool **ptr = new bool *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new bool[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr[i][j] = false;
        }
    }

    do
    {
        cout << "1) Toggle a value " << endl;
        cout << "2) Display array " << endl;
        cout << "3) Exit " << endl;
        cout << "enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int row, col;
            cout << "enter rows : ";
            cin >> row;

            cout << "enter cols : ";
            cin >> col;

            if (ptr[row][col] == false)
            {
                ptr[row][col] = true;
                cout<<"value toggled successfully"<<endl;
            }
            else
            {
                ptr[row][col] = false;
                cout<<"value toggled successfully"<<endl;
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << ptr[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        default:
            break;
        }

    } while (choice != 3);
    cout<<"exiting ..."<<endl;
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    

    return 0;
}