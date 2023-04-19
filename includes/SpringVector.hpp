#ifndef SPRINGVECTOR_HPP
#define SPRINGVECTOR_HPP


#include <string>
#include <stack>

#include "Spring.hpp"

using std::string;
using std::stack;

class SpringVector
{
    private:
        SpringVector();
        SpringVector(const SpringVector& src);
        
        SpringVector&   operator=(const SpringVector& src);
        ~SpringVector();

    public:

        static Spring&          equivalent_spring(string expr);
        static Spring&          equivalent_spring(string expr, vector<Spring>& springs);

        /* Util Functions */

    private:

        static bool             is_open(char c);
        static bool             is_close(char c);
        static bool             is_brace(char c);
        static bool             is_bracket(char c);

        static bool             matching(char a, char b);
};

#endif
