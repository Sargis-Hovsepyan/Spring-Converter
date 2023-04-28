#include "Complex.hpp"

/* Constructors and Destructor */

Complex::Complex() : _re(0), _im(0) {}

Complex::Complex(double re, double im) : _re(re), _im(im) {}

Complex::Complex(const Complex& src) { *this = src; }

Complex::~Complex() {}

Complex&    Complex::operator=(const Complex& src)
{
    this->_re = src._re;
    this->_im = src._im;

    return (*this);
}

/* Public Interface Functions */

Complex&    Complex::operator+(const Complex& rhs)
{
    this->_re += rhs._re;
    this->_im += rhs._im;

    return (*this);
}

Complex&    Complex::operator-(const Complex& rhs)
{
    this->_re -= rhs._re;
    this->_im -= rhs._im;

    return (*this);
}

Complex&    Complex::operator*(const Complex& rhs)
{
    this->_re = this->_re * rhs._re - this->_im * rhs._im;
    this->_im += this->_re * rhs._im + this->_im * rhs._re;

    return (*this);
}

double      Complex::get_real() const { return (this->_re); }
double      Complex::get_imeginary() const { return (this->_im); }

/* Output */

ostream&   operator<<(ostream& out, Complex num)
{
    bool case1 = (num._re > 0 && num._im > 0) || (num._re < 0 && num._im > 0);
    bool case2 = (num._re > 0 && num._im < 0) || (num._re < 0 && num._im < 0);

    if (case1)
        out << num._re << " + " << num._im << "i";
    else if (case2)
        out << num._re << " - " << -1 * num._im << "i";
    else
        out << 0;

    return (out);
}
