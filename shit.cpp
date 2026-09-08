#include <iostream>
using namespace std;

struct room
{
    int power;
    bool cursedFlag;
    bool sealedFlag;
};
struct floor
{
    room *rooms;
    int roomcount;
};

int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    room* rooms = new room[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter power"<<endl;
        cin>>rooms[i].power;

        cout<<"enter cursed bool"<<endl;
        cin>>rooms[i].cursedFlag;

        cout<<"enter sealed bool"<<endl;
        cin>>rooms[i].sealedFlag;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<rooms[i].power<<endl;

        cout<<rooms[i].cursedFlag<<endl;

        cout<<rooms[i].sealedFlag<<endl;
    }
    

    return 0;
}