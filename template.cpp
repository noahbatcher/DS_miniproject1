#include <string>
#include "template.hpp"
#include "crayon.hpp"
#include "ErrorT.hpp"

template <class T>

OrderedList<T>::OrderedList() : size(0), items{}
{
    for (int i = 0; i < MAX_ITEMS; ++i)
        items[i] = nullptr;
}

template <class T>
OrderedList<T>::~OrderedList()
{
    makeEmpty();
}

template <class T>
void OrderedList<T>::addItem(T &newItem)
{
    if (isFull())
    {
        throw ErrorT("Template is full. Cannot add more Items.");
    }

    if (size == 0)
    { // first item
        items[0] = new T(newItem);
        ++size;
        return;
    }

    int i;
    for (i = 0; i < size; ++i)
    {
        if (newItem < *items[i])
        {

            for (int j = size; j > i; j--)
            {
                items[j] = items[j - 1];
                opCount.moves++;
            }
            opCount.comparisons++;
            break;
        }
        opCount.comparisons++;
    }

    items[i] = new T(newItem);
    size++;
}

template <class T>
bool OrderedList<T>::removeItem(T &oldItem)
{
    for (int i = 0; i < size; ++i)
    {
        if (*items[i] == oldItem)
        {
            delete items[i];
            while (i < size - 1)
            {
                items[i] = items[i + 1];
                ++i;
                opCount.moves++;
            }
            --size;
            return true;
        }
        opCount.comparisons++;
    }
    opCount.comparisons++;
    throw ErrorT("Item not found in the items.");
    return false;
}

template <class T>
void OrderedList<T>::makeEmpty()
{
    for (int i = 0; i < size; ++i)
    {
        delete items[i];
        items[i] = nullptr;
        opCount.comparisons++;
    }
    size = 0;
}