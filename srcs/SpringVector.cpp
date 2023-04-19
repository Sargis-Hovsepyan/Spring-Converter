#include "SpringVectorVector.hpp"

/* Constructors and Destructor */

SpringVector::SpringVector() {}

SpringVector::SpringVector() {}

SpringVector::SpringVector(const SpringVector& other) {}

SpringVector::~SpringVector() {}

SpringVector&       SpringVector::operator=(const SpringVector& src) {}

/* Static Functions */

static Spring&      Spring::equivalent_string(string expr)
{
    stack<string>   stack;
    long            start;
    long            end;

    start = end = 0;
    stack.push(expr[0]);

    for (int i = 1; i < expr.size(); i++)
    {
        string top = stack.top();
        string curr = expr[i];
        
        if ()
    }
}

