#include "template.hpp"

template <typename T>
class OrderedListBlankSpace : public orderedList<T>
{
public:
    void addItem(T &newItem) override;
    bool removeItem(T &oldItem) override;
};