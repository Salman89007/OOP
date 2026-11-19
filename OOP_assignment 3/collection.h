#ifndef COLLECTION_H
#define COLLECTION_H

template <typename T>
class Collection {
private:
    T** items;
    int count;
    int capacity;

    void grow() {
        capacity *= 2;
        T** bigger = new T*[capacity];
        for (int i = 0; i < count; i++) bigger[i] = items[i];
        delete[] items;
        items = bigger;
    }

public:
    Collection() : items(new T*[4]), count(0), capacity(4) {}
    Collection(const Collection&) = delete;             // no accidental copies
    Collection& operator=(const Collection&) = delete;

    ~Collection() {
        for (int i = 0; i < count; i++) delete items[i];  // owns its items
        delete[] items;
    }

    void add(T* item) {
        if (count == capacity) grow();
        items[count++] = item;
    }
    T* get(int i) const { return (i >= 0 && i < count) ? items[i] : nullptr; }
    int size() const { return count; }
};

#endif