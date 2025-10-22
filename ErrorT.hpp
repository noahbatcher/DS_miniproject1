#ifndef ERRORT_HPP
#define ERRORT_HPP

#pragma once

#include <string>
#include <exception>

class ErrorT : public std::exception
{

private:
    std::string message;

public:
    ErrorT(const std::string &msg); // constructor
    const char *ErrorDesc() const;
};

#endif // ERRORT_HPP