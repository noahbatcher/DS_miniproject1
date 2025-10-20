#include <string>
#include "template.hpp"
#include "crayon.hpp"
#include "ErrorT.hpp"

template <class T>

OrderedList<T>::OrderedList() : size(0), items{}
{
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

    for (int i = 0; i < size; ++i)
    {
        if (newItem < *items[i])
        { // newItem is a lower number

            for (int j = size; j > i; j--)
            {
                items[j] = items[j - 1];
            }

            items[i] = new T(newItem);

            size++;
            return;
        }
    }
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
            }
            --size;
            return true;
        }
    }
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
    }
    size = 0;
}