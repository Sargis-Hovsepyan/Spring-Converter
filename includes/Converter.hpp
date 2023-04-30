#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "Complex.hpp"
#include "Spring.hpp"
#include "FT.hpp"

#include <string>
using std::string;

class Converter
{
    public:
        Converter();
        virtual ~Converter();

    public:
        virtual double       convert(const string& bits);

        virtual Spring       bits_to_spring(const string &bits) = 0;
        double               freq_to_decimal(vector<Complex> frequencies, vector<double> amplitudes);

        vector<double>      get_oscilations(Spring& spring, double start, double end, int n);
        vector<double>      get_frequencies(const vector<Complex>& amplitudes, double rate);
        vector<Complex>     get_amplitudes(const vector<double>& values);

        virtual void        validate(const string& bits) = 0;
};

#endif