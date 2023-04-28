#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

using std::ostream;

class Complex 
{
    private:
        double  _re;
        double  _im;

        friend ostream&   operator<<(ostream& out, Complex num);

    public:
        Complex();
        Complex(double re, double im);
        Complex(const Complex& src);
        ~Complex();

        Complex&    operator=(const Complex& src);

        Complex&    operator+(const Complex& rhs);
        Complex&    operator-(const Complex& rhs);
        Complex&    operator*(const Complex& rhs);

        double  get_real() const;
        double  get_imeginary() const;
};

ostream&   operator<<(ostream& out, Complex num);

#endif
