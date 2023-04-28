#ifndef FT_HPP
#define FT_HPP

#define PI   3.14159265358979323846

#include <algorithm>
#include <vector>
#include <cmath>

#include "Complex.hpp"
using std::vector;

class FT 
{
    private:
        FT();
        FT(const FT& src);
        ~FT();

    public:
        static void             fft(vector<Complex>& buffer);
        static int              bit_reverse(int x, int bits);
        
        static vector<double>   freq(double n, double time_step=1.0);
};

#endif
