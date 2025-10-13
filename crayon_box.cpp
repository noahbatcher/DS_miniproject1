#include <iostream>
#include <string>
#include "crayon_box.hpp"
#include "crayon.hpp"

// Linked List Node
struct Node
{
    Crayon data;
    Node *next;
    Node(const Crayon &c) : data(c), next(nullptr) {}
};

class CrayonBox
{
private:
    Node *head;

public:
    CrayonBox();
    ~CrayonBox();

    void addCrayon(const Crayon &crayon)
    {
    }
    bool removeCrayon(const std::string &color, const std::string &brand)
    {
    }

    bool isEmpty() const
    {
    }
    bool isFull() const
    {
    }
    void makeEmpty()
    {
    }
};