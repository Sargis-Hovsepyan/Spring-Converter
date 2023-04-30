#ifndef CONVERTER8BIT_HPP
#define CONVERTER8BIT_HPP

#include "Converter.hpp"
#include "SpringVector.hpp"

#include <stdexcept>
using std::to_string;

class Converter8Bit : public Converter 
{
    public:
        Converter8Bit();
        ~Converter8Bit();

    public:
        Spring  bits_to_spring(const string &bits);
        void    validate(const string& bits);
};

#endif