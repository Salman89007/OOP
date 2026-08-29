#include <iostream>
using namespace std;

void findTopper(char names[][20], int marks[], int n, int **topMarks, int *topIndex)
{
    cout << "enter student names : " << endl;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin.getline(names[i], 20);
    }
    cout << "enter marks : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> *(marks + i);
    }
    int maxSofar = marks[0];
    int maxIndex = 0;
    bool tie = false;

    for (int i = 1; i < n; i++)
    {
        if (*(marks + i) > maxSofar)
        {
            maxSofar = *(marks + i);
            maxIndex = i;
            tie = false;
        }
        else if (*(marks + i) == maxSofar)
        {
            tie = true;
        }
    }
    if (tie == true)
    {
        *topMarks = nullptr;
        *topIndex = -1;
    }
    else if(tie == false){
        *topMarks = &(*(marks+maxIndex));
        *topIndex = maxIndex;
    }
    
}

int main()
{
    int *topMarks;
    int index;
    int n;
    cout << "enter n for function to loop through : ";
    cin >> n;
    int marks[n];
    char name[n][20];

    findTopper(name, marks, n, &topMarks, &index);

    if (topMarks != nullptr)
    {
        cout<<"top marks are : "<<*topMarks<<"and the student is : "<<name[index]<<endl;
    }
    else{
        cout<<"marks were same so no winner"<<endl;
    }

    return 0;
}