#ifndef TASK3_HPP
#define TASK3_HPP

#pragma once

#include "ErrorT.hpp"
#include "template.hpp"

template <typename T>
class OrderedListBlankSpace : public OrderedList<T>
{
private:
    // Find nearest empty slot to the left
    int findLeftSpace(int startIndex)
    {
        for (int i = startIndex; i >= 0; --i)
        {
            if (this->items[i] == nullptr)
                return i;
        }
        return -1;
    }

    // Find nearest empty slot to the right
    int findRightSpace(int startIndex)
    {
        for (int i = startIndex; i < MAX_ITEMS; ++i)
        {
            if (this->items[i] == nullptr)
                return i;
        }
        return -1;
    }

    // Shift items left by 1 from [startIndex to endIndex]
    void moveItemsLeft(int startIndex, int endIndex)
    {
        for (int i = startIndex; i <= endIndex; ++i)
        {
            if (this->items[i] != nullptr)
            {
                this->items[i - 1] = this->items[i];
                this->items[i] = nullptr;
                this->opCount.moves++;
            }
        }
    }

    // Shift items right by 1 from [startIndex to endIndex]
    void moveItemsRight(int startIndex, int endIndex)
    {
        for (int i = endIndex; i >= startIndex; --i)
        {
            if (this->items[i] != nullptr)
            {
                this->items[i + 1] = this->items[i];
                this->items[i] = nullptr;
                this->opCount.moves++;
            }
        }
    }

public:
    void addItem(T &newItem) override
    {
        if (this->isFull())
            throw ErrorT("Template is full. Cannot add more items.");

        // find insertion point
        int insertIndex = 0;
        for (; insertIndex < MAX_ITEMS; ++insertIndex)
        {
            if (this->items[insertIndex] != nullptr)
            {
                this->opCount.comparisons++;
                if (*this->items[insertIndex] >= newItem)
                    break;
            }
            else
            {
                continue;
            }
        }

        // Insert directly if the spot next to it is empty
        if (insertIndex < MAX_ITEMS && this->items[insertIndex] == nullptr)
        {
            this->items[insertIndex] = new T(newItem);
            ++this->size;
            return;
        }

        // Finding the nearest empty slot
        int leftSpace = findLeftSpace(insertIndex - 1);
        int rightSpace = findRightSpace(insertIndex);

        // Shift to make room
        if (leftSpace != -1 && (rightSpace == -1 || (insertIndex - leftSpace <= rightSpace - insertIndex)))
        {
            moveItemsLeft(leftSpace, insertIndex - 1);
            this->items[insertIndex - 1] = new T(newItem);
        }
        else if (rightSpace != -1)
        {
            moveItemsRight(insertIndex, rightSpace - 1);
            this->items[insertIndex] = new T(newItem);
        }
        else
        {
            throw ErrorT("No space to insert item.");
        }

        ++this->size;
    }

    // Remove an item
    bool removeItem(T &oldItem) override
    {
        for (int i = 0; i < MAX_ITEMS; ++i)
        {
            if (this->items[i] != nullptr)
            {
                this->opCount.comparisons++;
                if (*this->items[i] == oldItem)
                {
                    delete this->items[i];
                    this->items[i] = nullptr;
                    --this->size;
                    return true;
                }
            }
        }
        throw ErrorT("Item not found in the list.");
        return false;
    }
};

#endif // TASK3_HPP
