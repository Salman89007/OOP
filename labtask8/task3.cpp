#include <iostream>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    Time &setHour(int hour)
    {
        return *this;
    }
    Time &setMinute(int minute)
    {
        return *this;
    }
    Time &setSecond(int second)
    {
        return *this;
    }
    Time &display()
    {
        cout << "Hour : " << this->hour << endl;
        cout << "Minute : " << this->minute << endl;
        cout << "Seconds : " << this->second << endl;
        return *this;
    }
};

int main()
{
    Time T(3, 25, 10);
    T.setHour(4).setMinute(50).setSecond(55).display();
    return 0;
}