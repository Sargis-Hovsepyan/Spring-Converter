#ifndef SPRINGVECTOR_HPP
#define SPRINGVECTOR_HPP

#include <stdexcept>
#include <string>
#include <stack>

#include "Spring.hpp"

using std::stringstream;
using std::string;
using std::stack;
using std::pair;

class SpringVector
{
    private:
        SpringVector();
        SpringVector(const SpringVector& src); 
        ~SpringVector();

    public:
        static Spring&          equivalent_spring(string expr);
        static Spring&          equivalent_spring(string expr, vector<Spring>& springs);

        /* UTIL FUNCTIONS */

    private:
        static bool             is_open(char c);
        static bool             is_close(char c);
        static bool             is_brace(char c);
        static bool             is_bracket(char c);

        static bool             matching(char a, char b);
        static void             add_springs(vector<pair<float, int>>& storage, pair<char, int> top);
};

#endif
