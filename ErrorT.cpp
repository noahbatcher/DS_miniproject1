#include "ErrorT.hpp"



ErrorT::ErrorT(const std::string& msg) : message(msg) {}

const char* ErrorT::ErrorDesc() const{
    return message.c_str();
}