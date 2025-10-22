
#ifndef Template_HPP
#define Template_HPP

#pragma once

#define MAX_ITEMS 20

#include <string>
#include <iostream>
#include "ErrorT.hpp"

struct OperationCount
{
    int comparisons = 0;
    int moves = 0;
};

// CrayonBox class representing a linked list of crayons
template <class T>
class OrderedList
{
protected:
    int size;
    T *items[MAX_ITEMS];
    OperationCount opCount;

public:
    OrderedList() : size(0), items{}
    {
        for (int i = 0; i < MAX_ITEMS; ++i)
            items[i] = nullptr;
    }

    ~OrderedList()
    {
        makeEmpty();
    }

    virtual void addItem(T &newItem)
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

    virtual bool removeItem(T &oldItem)
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

    void makeEmpty()
    {
        for (int i = 0; i < size; ++i)
        {
            delete items[i];
            items[i] = nullptr;
            opCount.comparisons++;
        }
        size = 0;
    }

    bool isFull() const
    {
        return size == MAX_ITEMS;
    }

    OperationCount getOperationCount()
    {
        return opCount;
    }

    void printItems()
    {
        for (int i = 0; i < MAX_ITEMS; i++) // <- you missed the '<'
        {
            if (items[i] != nullptr)
                std::cout << "Item " << i << ": " << *items[i] << std::endl;
            else
                std::cout << "Item " << i << ": [empty]" << std::endl;
        }
    }
};

#endif // Template_HPP