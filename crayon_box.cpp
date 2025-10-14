#include <string>
#include "crayon_box.hpp"
#include "crayon.hpp"
#include "ErrorT.hpp"

struct Node
{
    Crayon data;
    Node *next;
    Node(const Crayon &c) : data(c), next(nullptr) {}
};


// CrayonBox method implementations
CrayonBox::CrayonBox() : size(0), box {} {}

CrayonBox::~CrayonBox() { 

 }

void CrayonBox::addCrayon(Crayon &newCrayon)
{   
    if (isFull()) {
        throw ErrorT("CrayonBox is full. Cannot add more crayons.");
    }

    for (int i = 0; i < size; ++i) {
        if (box[i] == nullptr) { // Found an empty spot
            box[i] = new Crayon(newCrayon);
            ++size;
            return;

        }else if (newCrayon.getColor() < box[i]->getColor()) { // newCrayon is lower in alaphabet

            for (int j = i;  j < size; j++) {
                box[j] = box[j + 1];
            }

            box[i] = new Crayon(newCrayon);

            size++;
            return;
        }
    }
}

bool CrayonBox::removeCrayon(Crayon &oldCrayon)
{
       for (int i = 0; i < size; ++i) {
           if (box[i] != nullptr && box[i]->getColor() == oldCrayon.getColor()) {
               delete box[i];
               while (i < size - 1) {
                   box[i] = box[i + 1];
                   ++i;
               }
               --size;
               return true;
           }
       }
       throw ErrorT("Crayon not found in the box.");
       return false;
}

bool CrayonBox::isEmpty() const { 
    return size == 0; 
}

bool CrayonBox::isFull() const { 
    return size == MAX_CRAYONS; 
 }

void CrayonBox::makeEmpty()
{
    for (int i = 0; i < size; ++i) {
        delete box[i];
        box[i] = nullptr;
    }
    size = 0;
}