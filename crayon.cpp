#include <string>
#include "crayon.hpp"

class Crayon
{
private:
    std::string color;

public:
    // Constructors
    Crayon();
    Crayon(const std::string &c);

    // Gets
    std::string getColor() const;

    // Operator overloads
    bool operator==(const Crayon &other)
    {
        if (this->color[0] == other.color[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const Crayon &other)
    {
        if (this->color[0] < other.color[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Crayon &other)
    {
        if (this->color[0] > other.color[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
