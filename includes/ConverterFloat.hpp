#ifndef CONVERTERFLOAT_HPP
#define CONVERTERFLOAT_HPP

#include "Converter.hpp"
#include "SpringVector.hpp"

#include <stdexcept>
#include <algorithm>
using std::to_string;

class ConverterFloat : public Converter 
{
    public:
        ConverterFloat();
        ~ConverterFloat();

    public:
        Spring  bits_to_spring(const string &bits);
        void    validate(const string& bits);
};

#endif