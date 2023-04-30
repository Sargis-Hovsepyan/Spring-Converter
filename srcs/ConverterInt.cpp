#include "ConverterInt.hpp"

/* Constructor and Destructor */

ConverterInt::ConverterInt() : Converter() {}
ConverterInt::~ConverterInt() {}

/* Public Interface Functions */

Spring  ConverterInt::bits_to_spring(const string &bits)
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


void    ConverterInt::validate(const string& bits)
{ 
    if(bits.length() > 32)
        throw std::invalid_argument("Number of inputted bits should be less than or equal to 32, not " + to_string(bits.length()));
    
    for (unsigned long i = 0; i < bits.length(); i++)
        if(bits[i] != '0' && bits[i] != '1')
            throw std::invalid_argument("Illegal input " + string(1, bits[i]) + ", input should be either 1 or 0");
}