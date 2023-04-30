#include "ConverterFloat.hpp"

/* Constructor and Destructor */

ConverterFloat::ConverterFloat() : Converter() {}
ConverterFloat::~ConverterFloat() {}

/* Public Interface Functions */

Spring  ConverterFloat::bits_to_spring(const string &bits)
{
    validate(bits);
    unsigned long dot = bits.find('.');
    string expr = "[[";
    
    for (unsigned long i = 0; i < dot; i++)
    {
        if (bits[i] == '1')
        {
            expr += "[";
            for (unsigned long j = 0; j < pow(2, dot - i - 1); j++)
                expr += "[]";
			expr += "]";
		}
	}
    
    expr += "[";
    for (unsigned long i = dot + 1; i < bits.length(); i++)
    {
        if (bits[i] == '1')
        {
            expr += "{";
            for (unsigned long j = 0; j < pow(2, i - dot); j++)
                expr += "{}";
            expr += "}";
        }
    }
	
    if (expr[expr.length() - 1] == '[')
			expr.erase(expr.end() - 1);
	else
        expr += "]";

    expr += "]";
    return SpringVector::equivalent_spring(expr);
}

void    ConverterFloat::validate(const string& bits)
{
    if (std::count(bits.begin(), bits.end(), '.') != 1)
        throw std::invalid_argument("The input should contain a . (dot), which separates integer bits fron the fractional ones");

    if (!bits[bits.find('.') + 1])
        throw std::invalid_argument("If there is no fractional part just write a 0 after the . (dot)");
    
    for (unsigned long i = 0; i < bits.length(); i++)
        if(bits[i] != '0' && bits[i] != '1' && bits[i] != '.')
            throw std::invalid_argument("Illegal input " + string(1, bits[i]) + ", input should consist of either 1 or 0 separated by a . (dot)");
}