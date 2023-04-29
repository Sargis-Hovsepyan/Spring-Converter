#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
using std::ostream;

class Complex 
{
    private:
        long double  _re;
        long double  _im;

        friend ostream&   operator<<(ostream& out, Complex num);

    public:
        Complex();
        Complex(long double re, long double im);
        Complex(const Complex& src);
        ~Complex();

        Complex&    operator=(const Complex& src);

        Complex&    operator+(const Complex& rhs);
        Complex&    operator-(const Complex& rhs);
        Complex&    operator*(const Complex& rhs);

        long double  get_real() const;
        long double  get_imeginary() const;
};

ostream&   operator<<(ostream& out, Complex num);

#endif
