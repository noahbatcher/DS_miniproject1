#ifndef CRAYON_HPP
#define CRAYON_HPP

#include <string>

using std::string;

struct Node;

class Crayon
{
private:
    std::string color;

public:
    Crayon::Crayon() : color("") {}

    Crayon(const string& c) : color(c) {}

    string getColor() const { return color; }

    // Overloading comparison operators for Crayon
    bool operator<(const Crayon& other) const ;

    bool operator>(const Crayon& other) const ;

    bool operator==(const Crayon& other) const ;
};

#endif // CRAYON_HPP