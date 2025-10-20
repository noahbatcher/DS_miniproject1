#include "template.hpp"

template <typename T>
class OrderedListFromEnd : public orderedList<T>
{
public:
    // Override to search from the back toward the front when inserting.
    void addItem(const T &item) override;
};