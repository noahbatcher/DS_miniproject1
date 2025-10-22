#ifndef TASK3_HPP
#define TASK3_HPP

#pragma once

#include "ErrorT.hpp"
#include "template.hpp"

template <typename T>
class OrderedListBlankSpace : public OrderedList<T>
{
public:
    void addItem(T &newItem) override
    {
        if (this->isFull())
            throw ErrorT("Template is full. Cannot add more items.");

        if (this->size == 0)
        {
            this->items[0] = new T(newItem);
            ++this->size;
            return;
        }

        int insertIndex = 0;
        while (insertIndex < MAX_ITEMS && this->items[insertIndex] != nullptr && *this->items[insertIndex] < newItem)
        {
            this->opCount.comparisons++;
            ++insertIndex;
        }

        int left = insertIndex - 1;
        while (left >= 0 && this->items[left] == nullptr)
            --left;

        int right = insertIndex;
        while (right < MAX_ITEMS && this->items[right] == nullptr)
            ++right;

        int insertPos = -1;

        if (left >= 0 && right < MAX_ITEMS && right - left > 1)
        {
            insertPos = left + (right - left) / 2;
        }
        else if (left < 0)
        {
            insertPos = 0;
            for (int i = this->size; i > 0; --i)
            {
                this->items[i] = this->items[i - 1];
                this->opCount.moves++;
            }
        }
        else if (right >= MAX_ITEMS)
        {
            insertPos = MAX_ITEMS - 1;
        }
        else
        {
            insertPos = insertIndex;
            for (int i = MAX_ITEMS - 1; i > insertPos; --i)
            {
                if (this->items[i - 1] != nullptr)
                {
                    this->items[i] = this->items[i - 1];
                    this->items[i - 1] = nullptr;
                    this->opCount.moves++;
                }
            }
        }

        this->items[insertPos] = new T(newItem);
        ++this->size;
    }

    bool removeItem(T &oldItem) override
    {
        for (int i = 0; i < MAX_ITEMS; ++i)
        {
            if (this->items[i] != nullptr && *this->items[i] == oldItem)
            {
                delete this->items[i];
                this->items[i] = nullptr;
                --this->size;
                this->opCount.comparisons++;
                return true;
            }
        }

        throw ErrorT("Item not found in the items.");
        return false;
    }
};

#endif // TASK3_HPP
