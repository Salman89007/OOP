#include <iostream>
#include <iomanip>
using namespace std;

class Timestamp
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Timestamp(int h = 0, int m = 0, int s = 0)
    {
        if (h < 0 || m < 0 || s < 0)
        {
            throw invalid_argument("Invalid timestamp!");
        }

        minutes += s / 60;
        seconds = s % 60;

        minutes += m;
        hours = h + minutes / 60;
        minutes = minutes % 60;

        hours = hours % 24;
    }

    // Less Than Operator
    bool operator<(const Timestamp &rhs) const
    {
        if (hours < rhs.hours)
        {
            return true;
        }
        else if (hours == rhs.hours && minutes < rhs.minutes)
        {
            return true;
        }
        else if (hours == rhs.hours && minutes == rhs.minutes && seconds < rhs.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Greater Than Operator
    bool operator>(const Timestamp &rhs) const
    {
        return rhs < *this;
    }

    // Equality Operator
    bool operator==(const Timestamp &rhs) const
    {
        return hours == rhs.hours && minutes == rhs.minutes && seconds == rhs.seconds;
    }

    // Subtraction Operator
    long operator-(const Timestamp &rhs) const
    {
        long t1 = hours * 3600 + minutes * 60 + seconds;
        long t2 = rhs.hours * 3600 + rhs.minutes * 60 + rhs.seconds;

        return t1 - t2;
    }

    // Stream Extraction Operator
    friend istream &operator>>(istream &in, Timestamp &t)
    {
        int h, m, s;

        in >> h >> m >> s;

        if (in)
        {
            Timestamp temp(h, m, s);
            t = temp;
        }

        return in;
    }

    // Stream Insertion Operator
    friend ostream &operator<<(ostream &out, const Timestamp &t)
    {
        out << setfill('0') << setw(2) << t.hours << ":"
            << setw(2) << t.minutes << ":"
            << setw(2) << t.seconds;

        out << setfill(' ');

        return out;
    }
};

int main()
{

    try
    {
        Timestamp t1, t2;

        cout << "Enter first timestamp (HH MM SS): ";
        cin >> t1;

        cout << "Enter second timestamp (HH MM SS): ";
        cin >> t2;

        cout << endl;

        cout << "Timestamp 1: " << t1 << endl;
        cout << "Timestamp 2: " << t2 << endl;

        // Comparing timestamps
        if (t1 < t2)
        {
            cout << "First timestamp occurred earlier." << endl;
        }
        else if (t1 > t2)
        {
            cout << "Second timestamp occurred earlier." << endl;
        }
        else
        {
            cout << "Both timestamps are equal." << endl;
        }

        // Elapsed Seconds
        long elapsed = t2 - t1;

        cout << "Elapsed seconds: " << elapsed << endl;
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
