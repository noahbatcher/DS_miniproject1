#ifndef CRAYON_BOX_HPP
#define CRAYON_BOX_HPP

#include <string>
#include "crayon.hpp"

// CrayonBox class representing a linked list of crayons
class CrayonBox
{
private:
    Crayon *head;
    int size;

public:
    CrayonBox();
    ~CrayonBox();

    void addCrayon(const std::string &color);
    bool removeCrayon(const std::string &color);
    bool isEmpty() const;
    bool isFull() const;
    void makeEmpty();

    // Disable copy constructor and assignment
    CrayonBox(const CrayonBox &) = delete;
    CrayonBox &operator=(const CrayonBox &) = delete;
};

#endif // CRAYON_BOX_HPP