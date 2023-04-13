#ifndef SPRING_HPP
#define SPRING_HPP


#include <vector>
using std::vector;

class Spring
{
    private:
        double k = 1;
    
    public:
        Spring();
        Spring(const double k);
        Spring(const Spring& other);

        Spring&     operator=(const Spring& other);

        void        setK(double k);

        double*     move(double t, double dt, double x0, double v0);
        double*     move(double t, double dt, double x0);

        double*     move(double t0, double t1, double dt, double x0, double v0);
        double*     move(double t0, double t1, double dt, double x0, double v0, double m);

        Spring&     in_series(Spring that);
        Spring&     in_parallel(Spring that);


    /* UTILITY METHODS */
    
    private:
        Spring          in_series(const Spring& spring1, const Spring& spring2);
        Spring          in_parallel(const Spring& spring1, const Spring& spring2);

        vector<double>  get_all_coordinates(double t0, double t1, double dt, double x0, double v0,  double mass);

        double*         list_to_array(vector<double> coordinates);
        double          harmonic_motion_coordinate(double t, double omega, double c1, double c2);
};

#endif
