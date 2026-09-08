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
    char *name = new char[20];
    cin.getline(name, 20);
    int n;
    cout << "enter N" << endl;
    cin >> n;
    floor *f = new floor[n];
    for (int i = 0; i < n; i++)
    {
        f[i].roomcount = n - i;
        f[i].rooms = new room[f[i].roomcount];
    }
    int roomCounter = 0;
    int cursedCount = 0;
    int sealedCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < f[i].roomcount; j++)
        {
            roomCounter++;

            int floorNumber = i + 1;
            int roomNumber = j + 1;

            int power = (j + 1) * 10;

            if (floorNumber % 2 == 1 && roomNumber % 2 == 1) // if floor
            {                                                // and room number is odd then double the power, curse becomes true
                power = power * 2;
                f[i].rooms[j].cursedFlag = true;
                cursedCount++;
            }
            else
            {
                f[i].rooms[j].cursedFlag = false;
            }

            f[i].rooms[j].power = power;
            if (i == n - 1) // last floor = deepest floor = boss chamber
            {
                f[i].rooms[j].power = 99; // override, no matter what curse computed
            }

            if (roomCounter % 3 == 0)
            {
                f[i].rooms[j].sealedFlag = true;
                sealedCount++;
            }
            else
            {
                f[i].rooms[j].sealedFlag = false;
            }
        }
    }
    // print
    for (int i = 0; i < n; i++)
    {
        cout << "FLOOR " << (i + 1) << " ";
        for (int j = 0; j < f[i].roomcount; j++)
        {
            if (f[i].rooms[j].sealedFlag)
            {
                cout << "[LOCKED]";
            }
            else
            {
                cout << "[ " << f[i].rooms[j].power << " ]";
            }
        }
        cout << endl;
    }
    cout << "Rooms carved : " << roomCounter << "   Rooms wasted : 0" << endl;
    cout << "Cursed : " << cursedCount << "   Sealed : " << sealedCount << endl;

    delete[] name;
    for (int i = 0; i < n; i++)
    {
        delete[] (f + i)->rooms;
    }
    delete[] f;

    return 0;
}