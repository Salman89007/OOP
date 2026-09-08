#include <iostream>
using namespace std;

struct Room{
    int power;
    bool cursedFlag;
    bool sealedFlag;
};
struct Floor{
    Room* rooms; 
    int roomCount;
};
void RoomFunc(Room &room){
    room.cursedFlag = false;
    room.sealedFlag = false;
    room.power = 2;
}
void FloorFunc(Floor &floor){
    
}

int main()
{
    int n;
    Room r;
    Floor f;
    RoomFunc(r);
    FloorFunc(f);
    cout << "enter N" << endl;
    cin >> n;
    char name[] = "salman";
    
    int *number = new int[n];
    int **ptr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        number[i] = n-i;
        ptr[i] = new int[*(number+i)];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < *(number+i); j++)
        {
            cout << "enter for ptr[" << i << "]" << "[" << j << "]" << endl;
            cin >> *(*(ptr + i) + j);
        }
    }
    cout<<"NAME IS : "<<name<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < *(number+i); j++)
        {
            cout << "ptr[" << i << "]" << "[" << j << "]" <<" ";
            cout << *(*(ptr + i) + j)<<endl;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] *(ptr+i);
    }

    delete[] ptr;
    delete[] number;

    return 0;
}