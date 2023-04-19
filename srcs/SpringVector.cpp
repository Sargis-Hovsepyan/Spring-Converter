#include "SpringVector.hpp"

/* Constructors and Destructor */

SpringVector::SpringVector() {}

SpringVector::SpringVector(const SpringVector& other) { (void) other; }

SpringVector::~SpringVector() {}


/* Static Functions */

Spring&      SpringVector::equivalent_spring(string expr)
{
    stack<char>     stack;
    long            start;
    long            end;

    start = end = 0;
    stack.push(expr[0]);

    for (unsigned long i = 1; i < expr.size(); i++)
    {
        //char top = stack.top();
        //char curr = expr[i];
        
        // if ()
        start++;
    }

    return *(new Spring);
}

