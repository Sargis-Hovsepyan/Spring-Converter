#include "Converter8Bit.hpp"

/* Constructor and Destructor */

Converter8Bit::Converter8Bit() : Converter() {}
Converter8Bit::~Converter8Bit() {}

/* Public Interface Functions */

Spring  Converter8Bit::bits_to_spring(const string &bits)
{
    validate(bits);
    
    vector<Spring> springs;
    string reversed_bits = string(bits.rbegin(), bits.rend());
    string expr = "[";

    for (unsigned long index = 0; index < reversed_bits.length(); index++)
    {
        if(reversed_bits[index] == '1')
        {
            expr += "{}";
            springs.push_back(Spring(pow(2, index)));
        }
    }

    expr += "]";
    return SpringVector::equivalent_spring(expr, springs);
}

void    Converter8Bit::validate(const string& bits)
{
    if(bits.length() != 8)
        throw std::invalid_argument("Number of inputted bits should be 8, not " + to_string(bits.length()));
    
    for (unsigned long i = 0; i < bits.length(); i++)
        if(bits[i] != '0' && bits[i] != '1')
            throw std::invalid_argument("Illegal input " + string(1, bits[i]) + ", input should be either 1 or 0");
}