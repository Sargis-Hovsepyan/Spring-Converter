#ifndef FT_HPP
#define FT_HPP

#include <vector>

#include "Complex.hpp"
using std::vector;

class FT 
{
    private:
        FT();
        FT(const FT& src);
        ~FT();

    public:
        static void     fft(vector<Complex> buffer);
        static int      bit_reverse(int n, int bits);
};

#endif
