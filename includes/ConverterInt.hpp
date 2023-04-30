#ifndef CONVERTERINT_HPP
#define CONVERTERINT_HPP

#include "Converter.hpp"
#include "SpringVector.hpp"

#include <stdexcept>
using std::to_string;

class ConverterInt : public Converter 
{
    public:
        ConverterInt();
        ~ConverterInt();

    public:
        Spring  bits_to_spring(const string &bits);
        double  freq_to_decimal(vector<Complex> frequencies, vector<double> amplitudes);

        void    validate(const string& bits);
};

#endif