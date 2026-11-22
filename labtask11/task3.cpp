#include <iostream>
#include <stdexcept>
using namespace std;

class RingBuffer
{
private:
    int *buffer;
    int capacity;
    int count;
    int readCursor;

public:
    RingBuffer(int cap)
    {
        capacity = cap;
        count = 0;
        readCursor = 0;

        buffer = new int[capacity];
    }

    ~RingBuffer()
    {
        delete[] buffer;
    }

    void push(int reading)
    {
        if (count < capacity)
        {
            buffer[(readCursor + count) % capacity] = reading;
            count++;
        }
        else
        {
            buffer[readCursor] = reading;
            readCursor = (readCursor + 1) % capacity;
        }
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= count)
        {
            throw out_of_range("Invalid buffer index!");
        }

        return buffer[(readCursor + index) % capacity];
    }

    RingBuffer &operator++()
    {
        if (count > 0)
        {
            readCursor = (readCursor + 1) % count;
        }
        return *this;
    }

    RingBuffer operator++(int)
    {
        RingBuffer temp(*this);

        if (count > 0)
        {
            readCursor = (readCursor + 1) % count;
        }

        return temp;
    }

    bool operator!() const
    {
        return count == 0;
    }

    friend ostream &operator<<(ostream &out, const RingBuffer &b)
    {
        for (int i = 0; i < b.count; i++)
        {
            out << b.buffer[(b.readCursor + i) % b.capacity] << " ";
        }
        return out;
    }
};

int main()
{
    RingBuffer buf(4);
    if (!buf)
    {
        cout << "Buffer is empty!" << endl;
    }

    buf.push(10);
    buf.push(20);
    buf.push(30);
    buf.push(40);
    buf.push(50);

    cout << "After pushing 5 readings:" << endl;
    cout << buf << endl;

    cout << "Element at index 0: " << buf[0] << endl;
    cout << "Element at index 1: " << buf[1] << endl;

    ++buf;
    cout << "After Prefix ++buf:" << endl;
    cout << buf << endl;

    cout << "After Postfix buf++:" << endl;
    cout << buf << endl;

    RingBuffer old = buf++;

    cout << "Old state:" << endl;
    cout << old << endl;

    cout << "Current state:" << endl;
    cout << buf << endl;

    if (!buf)
    {
        cout << "Buffer is empty!" << endl;
    }
    else
    {
        cout << "Buffer is not empty!" << endl;
    }

    return 0;
}
