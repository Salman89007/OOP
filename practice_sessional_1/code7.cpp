#include <iostream>
#include <string>
using namespace std;

int main()
{
    char **name = new char *[3];
    string Name;
    int len;
    for (int i = 0; i < 3; i++)
    {
        getline(cin, Name);
        len = Name.length();
        name[i] = new char[len + 1];

        for (int j = 0; j < len; j++)
        {
            name[i][j] = Name[j];
        }

        name[i][len] = '\0';
    }

    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] name[i];
    }
    delete[] name;
    return 0;
}