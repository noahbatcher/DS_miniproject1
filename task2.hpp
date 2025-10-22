#ifndef TASK2_HPP
#define TASK2_HPP

#pragma once

#include "ErrorT.hpp"
#include "template.hpp"

template <typename T>
class OrderedListFromEnd : public OrderedList<T>
{
public:
    void addItem(T &newItem) override
    {
        bool found = false;

        if (this->isFull()) // is full check
        {
            throw ErrorT("List full. Cannot add item.");
        }

        if (this->size == 0) // checking that it isn't the first item
        {
            this->items[0] = new T(newItem);
            ++this->size;
            return;
        }

        int i;
        for (i = this->size - 1; i >= 0; --i)
        {
            if (!(*this->items[i] > newItem))
            {
                found = true;
                this->opCount.comparisons++;
                for (int j = this->size; j > i + 1; --j)
                {
                    this->items[j] = this->items[j - 1];
                    this->opCount.moves++;
                }
                break;
            }
        }

        if (found) // newitem > 0th element
        {
            this->items[i + 1] = new T(newItem);
            ++this->size;
        }
        else // newitem == or < 0th element
        {

            for (int j = this->size; j > 0; --j)
            {
                this->items[j] = this->items[j - 1];
                this->opCount.moves++;
            }

            this->items[0] = new T(newItem);
            ++this->size;
            this->opCount.comparisons++;
        }
    }
    using OrderedList<T>::removeItem;
};

#endif // TASK2_HPP
