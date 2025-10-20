#include "template.hpp"
#include "ErrorT.hpp"
#include "task2.hpp"

template <typename T>
class OrderedListFromEnd : public OrderedList<T>
{
public:
    void addItem(T &newItem)
    {
        if (this->isFull())
        {
            throw ErrorT("List full. Cannot add item.");
        }

        if (this->size == 0)
        {
            this->items[0] = new T(newItem);
            ++this->size;
            return;
        }

        int pos = this->size - 1;
        while (pos >= 0 && *this->items[pos] > newItem)
        {
            --pos;
        }

        // Shift items to make room
        for (int j = this->size; j > pos + 1; --j)
        {
            this->items[j] = this->items[j - 1];
        }

        this->items[pos + 1] = new T(newItem);
        ++this->size;
    }
};
