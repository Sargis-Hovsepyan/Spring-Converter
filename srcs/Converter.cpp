#include "Converter.hpp"

/* Constructor and Destructor */

Converter::Converter() {}
Converter::~Converter() {}

/* Public Interface Functions */

double      Converter::convert(const string& bits)
{
    int sampleSize = 1024;
    double t0 = 0;
    double t1 = 2 * PI;

    Spring spring = bits_to_spring(bits);
    
    vector<double>  values = get_oscilations(spring, t0, t1, sampleSize);
    vector<Complex> amplitudes = get_amplitudes(values);
    vector<double>  frequencies = get_frequencies(amplitudes, (t1 - t0) / sampleSize);

    return freq_to_decimal(amplitudes, frequencies);
}

vector<double>      Converter::get_oscilations(Spring& spring, double start, double end, int n)
{
    return spring.move(start, end, end / n, 1, 0, 0.001);
}

vector<double>      Converter::get_frequencies(const vector<Complex>& amplitudes, double rate)
{
    return FT::freq(amplitudes.size(), rate);
}

vector<Complex>     Converter::get_amplitudes(const vector<double>& values)
{
    vector<Complex> amplitudes(values.size());
 
    for (unsigned long i = 0; i < values.size(); i++)
        amplitudes[i] = Complex(values[i], 0.0);
        
    FT::fft(amplitudes);
    return amplitudes;
}