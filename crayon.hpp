#ifndef CRAYON_HPP
#define CRAYON_HPP

#include <string>

class Crayon
{
private:
    std::string color;

public:
    Crayon();                     // Default constructor
    Crayon(const std::string &c); // Constructor with color

    std::string getColor() const;

    // Overloaded comparison operators
    bool operator<(const Crayon &other) const;
    bool operator>(const Crayon &other) const;
    bool operator==(const Crayon &other) const;
};

#endif // CRAYON_HPP
