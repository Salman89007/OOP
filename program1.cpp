#include <iostream>
using namespace std;

void select(int *math, int *phy, int *chem, int **selected){
    if (*math > *phy && *math > *chem)
    {
        *selected = math;
    }
    else if (*phy > *math && *phy > *chem)
    {
        *selected = phy;
    }
    else if (*chem > *math && *chem > *phy)
    {
        *selected = chem;
    }
    else{
        *selected = nullptr;
    }
}

int main()
{
    int *selected = nullptr;
    int math, phy, chem;

    cout << "enter marks for maths " << endl;
    cin >> math;

    cout << "enter marks for phy " << endl;
    cin >> phy;

    cout << "enter marks for chem " << endl;
    cin >> chem;

    select(&math,&phy,&chem,&selected);

    if (selected != nullptr)
    {
        cout<<"subject with most marks : "<<*selected<<endl;
    }else{
        cout<<"marks are coinciding"<<endl;
    }

    return 0;
}