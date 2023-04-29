#include "Converter8Bit.hpp"

int main()
{
    Converter8Bit bit;
    
    std::cout << bit.convert("11110000") << std::endl;


    // This function gives you the amplitudes and takes the oscilations
    
    // void                FT::fft(vector<Complex>& buffer)
    // {
    //     int bits = (int) (log(buffer.size()) / log(2));

    //     for (unsigned long j = 1; j < buffer.size() / 2; j++) 
    //     {
    //         int swap_idx = bit_reverse(j, bits);

    //         Complex temp = buffer[j];
    //         buffer[j] = buffer[swap_idx];
    //         buffer[swap_idx] = temp;   
    //     }

    //     for (unsigned long N = 2; N <= buffer.size(); N <<= 1)
    //     {
    //         for (unsigned long i = 0; i < buffer.size(); i += N)
    //         {
    //             for (unsigned long k = 0; k < N / 2; k++)
    //             {
    //                 int even_idx = i + k;
    //                 int odd_idx = i + k + (N / 2);

    //                 Complex even = buffer[even_idx];
    //                 Complex odd = buffer[odd_idx];

    //                 double term = (-2 * PI * k) / (double) N;
    //                 Complex exp(cos(term), sin(term));
    //                 exp = (exp * odd);

    //                 buffer[even_idx] = (even + exp);
    //                 buffer[odd_idx] = (even - exp);
    //             }
    //         }
    //     }
    // }
    

    return 0;
}
