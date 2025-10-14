#ifndef CRAYON_BOX_HPP
#define CRAYON_BOX_HPP

#define MAX_CRAYONS 20

#include <string>
#include "crayon.hpp"


// CrayonBox class representing a linked list of crayons
class CrayonBox
{
private:
    int size;
    Crayon *box[MAX_CRAYONS];

public:
    CrayonBox();
    ~CrayonBox();

    void addCrayon(Crayon &newCrayon);
    bool removeCrayon(Crayon &oldCrayon);
    bool isEmpty() const;
    bool isFull() const;
    void makeEmpty();

    int getSize() const { return size; }
};

#endif // CRAYON_BOX_HPP