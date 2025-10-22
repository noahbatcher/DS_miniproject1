#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "template.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "ErrorT.hpp"

using namespace std;

#define REMOVE_ITEM 3
#define ADD_ITEM 4

OperationCount totalopCount_list1;
OperationCount totalopCount_list2;
OperationCount totalopCount_list3;

int randomAction(int removesLeft, int addsLeft)
{
    if (removesLeft == 0)
        return ADD_ITEM;

    if (addsLeft == 0)
        return REMOVE_ITEM;

    int r = std::rand() % (2);
    if (r == 0)
    {
        return REMOVE_ITEM;
    }
    else
    {
        return ADD_ITEM;
    }
}

void runTest()
{
    int removesLeft = 25;
    int addsLeft = 30;

    OrderedList<int> list1;           // Task 1: normal insert from front
    OrderedListFromEnd<int> list2;    // Task 2: insert from end
    OrderedListBlankSpace<int> list3; // Task 3: halfway insertion

    std::vector<int> randomNumbers;

    // Generate 30 random numbers between 1 and 100
    for (int i = 0; i < 30; ++i)
    {
        randomNumbers.push_back(std::rand() % 100 + 1);
    }

    int comparisons = 0;
    int moves = 0;

    // Insert into all 3 lists
    for (int i = 0; i < removesLeft + addsLeft; ++i)
    {
        int action = randomAction(removesLeft, addsLeft);
        if (action == REMOVE_ITEM)
        {
            int index = std::rand() % randomNumbers.size();
            int val = randomNumbers[index];
            try
            {
                list1.removeItem(val);
                list2.removeItem(val);
                list3.removeItem(val);
            }
            catch (ErrorT &e)
            {
                std::cerr << "Error removing: " << e.ErrorDesc() << "\n";
            }
            --removesLeft;
        }
        else
        {
            try
            {
                list1.addItem(randomNumbers[addsLeft - 1]);
                list2.addItem(randomNumbers[addsLeft - 1]);
                list3.addItem(randomNumbers[addsLeft - 1]);
            }
            catch (ErrorT &e)
            {
                std::cerr << "Error: " << e.ErrorDesc() << "\n";
            }
            --addsLeft;
        }
    }
    // adding totals
    totalopCount_list1.comparisons += list1.getOperationCount().comparisons;
    totalopCount_list1.moves += list1.getOperationCount().moves;
    totalopCount_list2.comparisons += list2.getOperationCount().comparisons;
    totalopCount_list2.moves += list2.getOperationCount().moves;
    totalopCount_list3.comparisons += list3.getOperationCount().comparisons;
    totalopCount_list3.moves += list3.getOperationCount().moves;
}

int main()
{
    std::srand(std::time(nullptr));

    for (int i = 0; i < 100; i++)
    {
        runTest();
    }

    cout << "List 1 (from front) - Total Comparisons: " << totalopCount_list1.comparisons << ", Total Moves: " << totalopCount_list1.moves << "\n";
    cout << "List 2 (from end) - Total Comparisons: " << totalopCount_list2.comparisons << ", Total Moves: " << totalopCount_list2.moves << "\n";
    cout << "List 3 (blank space insert) - Total Comparisons: " << totalopCount_list3.comparisons << ", Total Moves: " << totalopCount_list3.moves << "\n";
    return 0;
}
