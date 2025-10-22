#include "template.hpp"

template <typename T>
class OrderedListBlankSpace : public OrderedList<T>
{
public:
    void addItem(T &newItem) override;
    bool removeItem(T &oldItem) override;
};