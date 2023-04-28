#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "Spring.hpp"
#include <string>

using std::string;

class Converter
{
    private:
        Converter();
        Converter(const Converter &src);
        ~Converter();

    public:
        virtual static double       convert(const string& bits) = 0;

        virtual static Spring       bits_to_spring(const string &bits) = 0;
        virtual static double       freq_to_decimal(vector<Complex> frequencies, vector<double> amplitudes) = 0;

        static vector<double>&      get_oscilations(const Spring& spring, double start, double end, int n);
        static vector<double>&      get_frequencies(const vector<Complex>& amplitudes, double rate);
        static vector<Complex>&     get_amplitudes(const vector<double>& coordinates, double rate);
};

#endif