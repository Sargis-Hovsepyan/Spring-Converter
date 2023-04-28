#include "Converter.hpp"

/* Constructors and Destructor */

Converter::Converter() {}
Converter::Converter(const Converter& src) { (void)src; }
Converter::~Converter() {}

/* Public Interface Functions */


vector<double>      Converter::get_oscilations(Spring& spring, double start, double end, int n)
{
    return spring.move(start, end, end / n, 1, 0, 0.001);
}

vector<double>      Converter::get_frequencies(const vector<Complex>& amplitudes, double rate)
{
    return FT::freq(amplitudes.size(), rate);
}

vector<Complex>     Converter::get_amplitudes(const vector<double>& coordinates)
{
    vector<Complex> amplitudes(coordinates.size());
 
    for (unsigned long i = 0; i < coordinates.size(); i++)
        amplitudes[i] = *(new Complex(coordinates[i], 0.0));
        
    FT::fft(amplitudes);
    return amplitudes;
}