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
// part b
const room *findStrongest(const room *const rooms, int roomCount)
{
    const room *strongest = nullptr;
    for (int i = 0; i < roomCount; i++)
    {
        if ((rooms + i)->sealedFlag == 1)
        {
            continue;
        }

        if (strongest == nullptr || (rooms + i)->power > strongest->power)
        {
            strongest = rooms + i;
        }
    }
    return strongest;
}
void printAny(void *data, char type)
{
    if (type == 'i')
        cout << *(int *)data << endl;
    else if (type == 'f')
        cout << *(float *)data << endl;
    else if (type == 'c')
        cout << *(char *)data << endl;
}
void destroyDungeon(floor **fPtr, char **namePtr, int n)
{
    floor *f = *fPtr;
    for (int i = 0; i < n; i++)
    {
        delete[] f[i].rooms;
        cout << "Floor " << (n - i) << " freed ... ok" << endl;
    }
    delete[] f;
    cout << "Floor table freed ... ok" << endl;
    delete[] *namePtr;
    cout << "Hero name freed ... ok" << endl;
    *fPtr = nullptr;
    *namePtr = nullptr;
}
int main()
{
    string temp;
    getline(cin, temp);
    int len = temp.length();
    char *name = new char[len + 1];
    for (int i = 0; i < len; i++)
        name[i] = temp[i];
    name[len] = '\0';
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
    int demoInt = f[0].rooms[0].power; 
    cout << "Debug print (int): ";
    printAny(&demoInt, 'i');

    float demoFloat = 3.14f;
    cout << "Debug print (float): ";
    printAny(&demoFloat, 'f');

    char demoChar = name[0]; 
    cout << "Debug print (char): ";
    printAny(&demoChar, 'c');
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

    // finding the strongest
    const room *overallBest = nullptr;
    int bestFloor = -1;
    int bestRoom = -1;
    for (int i = 0; i < n; i++)
    {
        const room *candidate = findStrongest(f[i].rooms, f[i].roomcount);
        if (candidate != nullptr)
        {
            if (overallBest == nullptr || candidate->power > overallBest->power)
            {
                overallBest = candidate;
                bestFloor = i + 1;
                bestRoom = (candidate - f[i].rooms) + 1; // pointer subtraction to recover which room index this was
            }
        }
    }
    if (overallBest != nullptr)
    {
        cout << "Strongest monster : " << overallBest->power
             << " (Floor " << bestFloor << ", Room " << bestRoom << ")" << endl;
    }
    if (f[n - 1].rooms[0].sealedFlag)
    {
        cout << ">>> BOSS CHAMBER SEALED - RUN INCOMPLETE <<<" << endl;
    }
    // freeing the memory
    destroyDungeon(&f, &name, n);
    return 0;
}