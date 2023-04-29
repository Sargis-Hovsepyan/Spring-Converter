#include "Spring.hpp"

/* Constructors and Destructor */

Spring::Spring() : _k(1) {}
Spring::Spring(const double k) : _k(k) {}
Spring::Spring(const Spring& other) { *this = other; }
Spring::~Spring() {}

Spring&     Spring::operator=(const Spring& src)
{
    this->_k = src._k;
    return(*this);
}


/* Setters and Getters */


double      Spring::get_k() const { return (this->_k); }

void        Spring::set_k(double k) { this->_k = k; }


/* Move Functions */


vector<double>      Spring::move(double t, double dt, double x0)
{ 
    return get_values(0, t, dt, x0, 0, 0);
}

vector<double>      Spring::move(double t, double dt, double x0, double v0)
{
    return get_values(0, t, dt, x0, v0, 0);
}

vector<double>      Spring::move(double t0, double t1, double dt, double x0, double v0)
{
    return get_values(t0, t1, dt, x0, v0, 0);
}

vector<double>      Spring::move(double t0, double t1, double dt, double x0, double v0, double m)
{
    return get_values(t0, t1, dt, x0, v0, m);
}


/* Connect Functions */

Spring&             Spring::operator+(const Spring& s)
{
    this->_k += s._k;
    return (*this);
}

Spring&             Spring::operator*(const Spring& s)
{
    this->_k = (this->_k * s._k) / (this->_k + s._k);
    return (*this);
}


/* UTILITY METHODS */

vector<double>      Spring::get_values(double t0, double t1, double dt, double x0, double v0,  double mass)
{
    vector<double> values;

    double curr_time = t0; 
    double omega = sqrt(_k / mass);

    double c1 = x0;
    double c2 = v0 / omega;
    
    while (curr_time < t1)
    {
        double p = simple_harmonic_motion(curr_time, omega, c1, c2);
        values.push_back(p);
        curr_time += dt;
    }

    return values;
}

double          Spring::simple_harmonic_motion(double t, double omega, double c1, double c2)
{
    return (c1 * cos(omega * t) + c2 * sin(omega * t));
}
