#include "crayon.hpp"
#include <cctype>

Crayon::Crayon() : color("") {}

Crayon::Crayon(const std::string &c) : color(c) {}

std::string Crayon::getColor() const
{
    return color;
}

bool Crayon::operator==(const Crayon &other) const
{
    return color == other.color;
}

bool Crayon::operator<(const Crayon &other) const
{
    for (size_t i = 0; i < color.length() && i < other.color.length(); ++i)
    {
        if (tolower(color[i]) < tolower(other.color[i]))
            return true;
        else if (tolower(color[i]) > tolower(other.color[i]))
            return false;
    }
    return color.length() < other.color.length();
}

bool Crayon::operator>(const Crayon &other) const
{
    for (size_t i = 0; i < color.length() && i < other.color.length(); ++i)
    {
        if (tolower(color[i]) > tolower(other.color[i]))
            return true;
        else if (tolower(color[i]) < tolower(other.color[i]))
            return false;
    }
    return color.length() > other.color.length();
}
