#include <string>
#include "crayon.hpp"

// Implementations for Crayon declared in crayon.hpp
Crayon::Crayon() : color("") {}

Crayon::Crayon(const std::string &c) : color(c) {}

std::string Crayon::getColor() const { 
    return color; 
}

bool Crayon::operator==(const Crayon &other) const { 
    return color == other.color; 
}

bool Crayon::operator<(const Crayon &other) const { 

    for (int i = 0; i < color.length() && i < other.color.length(); ++i) {
        if (tolower(color[i]) < tolower(other.color[i])) {
            return true;
        }else if (color[i] == other.color[i]) {
            continue;
        }else{
            break;
        }
    }

    return false;
}

bool Crayon::operator>(const Crayon &other) const { 
    for (int i = 0; i < color.length() && i < other.color.length(); ++i) {
        if (tolower(color[i]) > tolower(other.color[i])) {
            return true;
        }else if (color[i] == other.color[i]) {
            continue;
        }else{ //color[i] < other.color[i]
            break;
        }
    }

    return false;
}
