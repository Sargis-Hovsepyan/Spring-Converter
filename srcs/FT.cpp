#include "FT.hpp"

/* Constructors and Destructor */

FT::FT() {}
FT::FT(const FT& src) { (void)src; }
FT::~FT() {}

/* Public Static Functions */

void                FT::fft(vector<Complex>& buffer)
{
    int bits = (int) (log(buffer.size()) / log(2));

    for (unsigned long j = 1; j < buffer.size() / 2; j++) 
    {
        int swap_idx = bit_reverse(j, bits);

        Complex temp = buffer[j];
        buffer[j] = buffer[swap_idx];
        buffer[swap_idx] = temp;   
    }

    for (unsigned long N = 2; N <= buffer.size(); N <<= 1)
    {
        for (unsigned long i = 0; i < buffer.size(); i += N)
        {
            for (unsigned long k = 0; k < N / 2; k++)
            {
                int even_idx = i + k;
                int odd_idx = i + k + (N / 2);

                Complex even = buffer[even_idx];
                Complex odd = buffer[odd_idx];

                double term = (-2 * PI * k) / (double) N;
                Complex exp(cos(term), sin(term));
                exp = (exp * odd);

                buffer[even_idx] = (even + exp);
                buffer[odd_idx] = (even - exp);
            }
        }
    }
}

int                 FT::bit_reverse(int x, int bits)
{
    int n = x;
    int count = bits - 1;

    x >>= 1;
    while (x > 0)
    {
        n = (n << 1) | (x & 1);
        count--;
        x >>= 1;
    }

    return ((n << count) & ((1 << bits) - 1));
}

vector<double>      FT::freq(double n, double time_step)
{
    vector<double>  v;
    vector<double> result;

    double c = 1 / (n * time_step);
    double N = floor((n - 1) / 2) + 1;

    for (double i = 0; i < N - 1; i++)
        v.push_back(i);

    for (double i = -1 * floor(n/2); i < 0; i++)
        v.push_back(i);

    transform(v.begin(), v.end(), back_inserter(result), [c](double num) { return num * c; });

    return result;
}