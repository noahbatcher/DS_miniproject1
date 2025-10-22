#ifndef Template_HPP
#define Template_HPP

#define MAX_ITEMS 20

#include <string>

struct OperationCount
{
    int comparisons = 0;
    int moves = 0;
};

// CrayonBox class representing a linked list of crayons
template <class T>
class OrderedList
{
private:
    int size;
    T *items[MAX_ITEMS];
    OperationCount opCount;

public:
    OrderedList();
    ~OrderedList();

    virtual void addItem(T &newItem);
    virtual bool removeItem(T &oldItem);
    bool isEmpty() const { return size == 0; };
    bool isFull() const { return size == MAX_ITEMS };
    void makeEmpty();
    OperationCount getOperationCount() { return opCount; }
};

#endif // Template_HPP