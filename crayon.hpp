#ifndef CRAYON_HPP
#define CRAYON_HPP

#include <string>

class Crayon
{
private:
    std::string color;

public:
    // default constructor
    Crayon() : color("") {}

    // parameterized constructor
    Crayon(const std::string &color)
        : color(color) {}

    // Overload equality operator
    bool operator==(const Crayon &other) const;

    // Overload less-than operator
    bool operator<(const Crayon &other) const;

    // overload greater-than operator
    bool operator>(const Crayon &other) const;

    // Getters
    std::string getColor() const;
};

#endif // CRAYON_HPP