#include <iostream>
#include<string>
using namespace std;

int main() {

    string name;
    getline(cin,name);
    int len;
    len = name.length();
    char * c = new char[len+1];
    for (int i = 0; i < len; i++)
    {
        c[i] = name[i];
    }
    c[len+1] = '\0';
    cout<<"now gonna display the name : ";
    for (int i = 0; i < len+1; i++)
    {
        cout<<c[i];
    }
    
    delete[] c;
    return 0;
}