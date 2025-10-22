#include "template.hpp"
#include "ErrorT.hpp"
#include "task2.hpp"

template <typename T>
void OrderedListFromEnd<T>::addItem(T &newItem)
{
    if (this->isFull())
    {
        throw ErrorT("List full. Cannot add item.");
    }

    if (this->size == 0)
    { // first item
        this->items[0] = new T(newItem);
        ++this->size;
        return;
    }

    for (int i = this->size - 1; i >= 0; --i)
    {
        if (!(*this->items[i] > newItem)) // no nullptr needed because the size is controlled
        {
            opCount.comparisons++;
            for (int j = this->size; j > i + 1; --j)
            {
                this->items[j] = this->items[j - 1];
                opCount.moves++;
            }
            break;
        }
    }

    this->items[i + 1] = new T(newItem);
    ++this->size;
}
