#include "spring.hpp"

/* Constructors and Destructor */

Spring::Spring() : _k(1) {}

Spring::Spring(const double k) : _k(k) {}

Spring::Spring(const Spring& other) { *this = other; }

Spring::~Spring() {}

Spring&     Spring::operator=(const Spring& other)
{
    this->_k = other._k;
    return(*this);
}


/* Public Interface Functions */

void        Spring::set_k(double k) { this->_k = k; }

void        Spring::get_k(double k) const { return (this->_k); }

double*     Spring::move(double t, double dt, double x0, double v0)
{
    vector<double>  coordinates = get_all_coordinates(0, t, dt, x0, v0, NULL);
    return coordinates.data();
}

/* UTILITY METHODS */

vector<double>  Spring::get_all_coordinates(double t0, double t1, double dt, double x0, double v0,  double mass=1)
{
    vector<double> coordinates;
    double curr_time = t0;
    
    double omega = sqrt(_k / mass);
    double c1 = x0;
    double c2 = v0 / omega;
    
    while (curr_time < t1)
    {
        double coordinate = harmonic_motion_coordinate(curr_time, omega, c1, c2);
        coordinates.push_back(coordinate);
        curr_time += dt;
    }

    return coordinates;
}

double          Spring::harmonic_motion_coordinate(double t, double omega, double c1, double c2)
{
    return (c1 * cos(omega * t) + c2 * sin(omega * t));
}
