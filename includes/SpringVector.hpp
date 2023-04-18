#ifndef SPRINGVECTOR_HPP
#define SPRINGVECTOR_HPP

#include "Spring.hpp"
#include <string>
using std::string;

class SpringVector
{
    private:
        SpringVector();
        SpringVector(const SpringVector& src);
        
        SpringVector&   operator=(const SpringVector& src);
        ~SpringVector();

    public:

        static Spring&  equivalent_spring(string expr);
        static Spring&  equivalent_spring(string expr, vector<Spring>& springs);
};

#endif
