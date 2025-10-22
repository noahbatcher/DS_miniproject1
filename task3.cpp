#include "task3.hpp"
#include <cmath>
#include "ErrorT.hpp"

#include "task3.hpp"
#include "ErrorT.hpp"
#include <cmath>

template <class T>
void OrderedListBlankSpace<T>::addItem(T &newItem)
{
    if (isFull())
        throw ErrorT("Template is full. Cannot add more items.");

    // First item
    if (size == 0)
    {
        items[0] = new T(newItem);
        ++size;
        return;
    }

    // Find the logical insert index
    int insertIndex = 0;
    while (insertIndex < MAX_ITEMS && items[insertIndex] != nullptr && *items[insertIndex] < newItem)
    {
        opCount.comparisons++;
        ++insertIndex;
    }
    // Find left neighbor
    int left = insertIndex - 1;
    while (left >= 0 && items[left] == nullptr)
        --left;

    // Find right neighbor
    int right = insertIndex;
    while (right < MAX_ITEMS && items[right] == nullptr)
        ++right;

    int insertPos = -1;

    // Case 1: Space exists between neighbors -> insert halfway
    if (left >= 0 && right < MAX_ITEMS && right - left > 1)
    {
        insertPos = left + (right - left) / 2;
    }
    // Case 2: No space to the left, insert at beginning if smaller than all
    else if (left < 0)
    {
        insertPos = 0;
        for (int i = size; i > 0; --i)
        {
            items[i] = items[i - 1];
            opCount.moves++;
        }
    }

    // Case 3: No space to the right, insert at last available slot
    else if (right >= MAX_ITEMS)
    {
        insertPos = MAX_ITEMS - 1;
    }
    // Case 4: Contiguous neighbors, shift right to make room
    else
    {
        insertPos = insertIndex;
        for (int i = MAX_ITEMS - 1; i > insertPos; --i)
        {
            if (items[i - 1] != nullptr)
            {
                items[i] = items[i - 1];
                items[i - 1] = nullptr;
                opCount.moves++;
            }
        }
    }

    items[insertPos] = new T(newItem);
    ++size;
}

template <class T>
bool OrderedListBlankSpace<T>::removeItem(T &oldItem)
{
    for (int i = 0; i < MAX_ITEMS; ++i)
    {
        if (items[i] != nullptr && *items[i] == oldItem)
        {
            delete items[i];
            items[i] = nullptr;
            --size;
            opCount.comparisons++;
            return true;
        }
    }

    throw ErrorT("Item not found in the items.");
    return false;
}
