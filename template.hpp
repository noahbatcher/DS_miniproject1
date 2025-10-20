#ifndef Template_HPP
#define Template_HPP

#define MAX_ITEMS 20

#include <string>

// CrayonBox class representing a linked list of crayons
template <class T>
class OrderedList
{
private:
    int size;
    T *items[MAX_ITEMS];

public:
    OrderedList();
    ~OrderedList();

    virtual void addItem(T &newCrayon);
    bool removeItem(T &oldCrayon);
    bool isEmpty() const { return size == 0; };
    bool isFull() const { return size == MAX_ITEMS };
    void makeEmpty();
};

#endif // Template_HPP