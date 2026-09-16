#include <iostream>
#include<string>
using namespace std;

struct room{
    int power;
    bool cursedFlag;
    bool sealedFlag;
};
struct floor{
    room *rooms;
    int roomcount;
};
const room *findStrongest(const room *const rooms, int roomCount)
{
    const room *strongest = nullptr;
    for (int i = 0; i < roomCount; i++)//looping through 15 rooms
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
        delete[] (f + i)->rooms;
        cout << "Floor " << (n - i) << " freed ... ok" << endl;
    }
    delete[] f;
    cout << "Floor table freed ... ok" << endl;
    delete[] *namePtr;
    cout << "Hero name freed ... ok" << endl;
    *fPtr = nullptr;
    *namePtr = nullptr;
}
int main() {
    string name;
    cout<<"enter name : "<<endl;
    getline(cin,name);
    int len = name.length();
    char* Name= new char[len+1];
    for (int i = 0; i < len; i++)
    {
        Name[i] = name[i];
    }
    Name[len]  = '\0';
    int n = 5; //number of floors
    floor* f = new floor[n];
    for (int i = 0; i < n; i++)
    {
        f[i].roomcount = n-i;
        f[i].rooms = new room[f[i].roomcount];
    }
    int roomCount = 0;
    int cursedCount = 0;
    int sealedCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < f[i].roomcount; j++)
        {
            roomCount++;
            int floorNumber = i + 1;
            int roomNumber = j + 1;
            int power = (j + 1) * 10;
            if (floorNumber %2 == 1 && roomNumber %2 == 1)
            {
                power *= 2;
                f[i].rooms[j].cursedFlag = true;
                cursedCount++;
            }else{
                f[i].rooms[j].cursedFlag = false;
            }
            f[i].rooms[j].power = power;
            if (i == n - 1) // last floor = deepest floor = boss chamber
            {
                ((f + i)->rooms + j)->power = 99; // override, no matter what curse computed
            }
            if (roomCount % 3 == 0)
            {
                ((f + i)->rooms + j)->sealedFlag = true;
                sealedCount++;
            }
            else
            {
                ((f + i)->rooms + j)->sealedFlag = false;
            }
        }
    }
    int demoInt = (f + 0)->rooms->power; 
    cout << "Debug print (int): ";
    printAny(&demoInt, 'i');

    float demoFloat = 3.14f;
    cout << "Debug print (float): ";
    printAny(&demoFloat, 'f');

    char demoChar = *Name; 
    cout << "Debug print (char): ";
    printAny(&demoChar, 'c');

    for (int i = 0; i < n; i++)
    {
        cout << "FLOOR " << (i + 1) << " ";
        for (int j = 0; j < (f + i)->roomcount; j++)
        {
            if (((f + i)->rooms + j)->sealedFlag)
            {
                cout << "[LOCKED]";
            }
            else
            {
                cout << "[ " << ((f + i)->rooms + j)->power << " ]";
            }
        }
        cout << endl;
    }
    cout << "Rooms carved : " << roomCount << "   Rooms wasted : 0" << endl;
    cout << "Cursed : " << cursedCount << "   Sealed : " << sealedCount << endl;

    const room* overallbest = nullptr;
    int bestFloor = -1;
    int bestRoom = -1;
    for (int i = 0; i < n; i++)
    {
        const room* candidate = findStrongest(f[i].rooms,f[i].roomcount);
        if (candidate!=nullptr)
        {
            if (overallbest == nullptr || candidate->power > overallbest->power)
            {
                overallbest = candidate;//shallow copy
                bestFloor = i + 1;
                bestRoom = (candidate - (f + i)->rooms) + 1;
            }
        }
    }
    if (overallbest != nullptr)
    {
        cout << "Strongest monster : " << overallbest->power
             << " (Floor " << bestFloor << ", Room " << bestRoom << ")" << endl;
    }
    if ((f + (n - 1))->rooms->sealedFlag)
    {
        cout << ">>> BOSS CHAMBER SEALED - RUN INCOMPLETE <<<" << endl;
    }
    destroyDungeon(&f, &Name, n);
    return 0;
}