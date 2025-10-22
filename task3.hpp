#ifndef TASK3_HPP
#define TASK3_HPP

#pragma once

#include "ErrorT.hpp"
#include "template.hpp"

template <typename T>
class OrderedListBlankSpace : public OrderedList<T>
{
private:
    void moveItemsRight(int startIndex, int endIndex)
    {
        if (startIndex >= endIndex || startIndex < 0 || endIndex > MAX_ITEMS)
            return;
        for (int i = endIndex; i > startIndex; --i)
        {
            if (this->items[i - 1] != nullptr)
            {
                this->items[i] = this->items[i - 1];
                this->items[i - 1] = nullptr;
                this->opCount.moves++;
            }
            this->opCount.comparisons++;
        }
    }

    void moveItemsLeft(int startIndex, int endIndex)
    {
        if (startIndex >= endIndex || startIndex < 0 || endIndex >= MAX_ITEMS)
            return;
        for (int i = startIndex; i < endIndex; ++i)
        {
            if (this->items[i + 1] != nullptr)
            {
                this->items[i] = this->items[i + 1];
                this->items[i + 1] = nullptr;
                this->opCount.moves++;
            }
            this->opCount.comparisons++;
        }
    }

    int findItemLeft(int startIndex)
    {
        for (int i = std::min(startIndex, MAX_ITEMS - 1); i >= 0; --i)
        {
            if (this->items[i] != nullptr)
            {
                this->opCount.comparisons++;
                return i;
            }
            this->opCount.comparisons++;
        }
        return -1;
    }

    int findItemRight(int startIndex)
    {
        for (int i = std::max(0, startIndex); i < MAX_ITEMS; ++i)
        {
            if (this->items[i] != nullptr)
            {
                this->opCount.comparisons++;
                return i;
            }
            this->opCount.comparisons++;
        }
        return -1;
    }

    int findLeftSpace(int startIndex)
    {
        for (int i = std::min(startIndex, MAX_ITEMS - 1); i >= 0; --i)
        {
            if (this->items[i] == nullptr)
            {
                this->opCount.comparisons++;
                return i;
            }
            this->opCount.comparisons++;
        }
        return -1;
    }

    int findRightSpace(int startIndex)
    {
        for (int i = std::max(0, startIndex); i < MAX_ITEMS; ++i)
        {
            if (this->items[i] == nullptr)
            {
                this->opCount.comparisons++;
                return i;
            }
            this->opCount.comparisons++;
        }
        return -1;
    }

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
        while (insertIndex < MAX_ITEMS)
        {
            if (this->items[insertIndex] == nullptr || *this->items[insertIndex] > newItem)
            {
                this->opCount.comparisons++;
                break;
            }
            this->opCount.comparisons++;
            ++insertIndex;
        }

        if (insertIndex >= MAX_ITEMS)
            insertIndex = MAX_ITEMS - 1;

        int rightMostIndex = findItemLeft(MAX_ITEMS - 1);
        int insertPos;

        if (rightMostIndex == -1)
        {
            insertPos = MAX_ITEMS / 2;
        }
        else if (rightMostIndex == insertIndex)
        {
            if (*this->items[rightMostIndex] >= newItem)
            {
                int spaceLeft = findLeftSpace(rightMostIndex - 1);
                if (spaceLeft != -1)
                    moveItemsLeft(spaceLeft, rightMostIndex);
                insertPos = rightMostIndex;
            }
            else
            {
                int leftSpaceInd = findLeftSpace(insertIndex - 1);
                int leftItemInd = findItemLeft(insertIndex - 1);
                if (leftSpaceInd > leftItemInd && leftSpaceInd != -1)
                    insertPos = leftItemInd + (insertIndex - leftItemInd) / 2;
                else if (leftSpaceInd != -1)
                {
                    moveItemsLeft(leftSpaceInd, insertIndex - 1);
                    insertPos = insertIndex - 1;
                }
                else
                    throw ErrorT("No space to insert item to the left.");
            }
        }
        else
        {
            int rightItemInd = findItemRight(insertIndex);
            if (rightItemInd == -1)
                rightItemInd = MAX_ITEMS - 1;
            int rightSpaceInd = findRightSpace(insertIndex);
            if (rightSpaceInd == -1)
                rightSpaceInd = MAX_ITEMS - 1;

            if (rightSpaceInd < rightItemInd)
                insertPos = insertIndex + (rightItemInd - insertIndex) / 2;
            else if (rightSpaceInd != -1)
            {
                moveItemsRight(insertIndex + 1, rightMostIndex + 1);
                insertPos = insertIndex;
            }
            else
            {
                int leftSpace = findLeftSpace(insertIndex - 1);
                if (leftSpace != -1)
                    moveItemsLeft(leftSpace, insertIndex);
                insertPos = insertIndex;
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
