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
        char top = stack.top();
        char curr = expr[i];
        
        if (is_open(curr) && is_open(top))
            stack.push(curr);
    }

    return *(new Spring);
}


/* UTIL FUNCTIONS */

bool        SpringVector::is_open(char c) { return  (c == '}' || c == ']'); }
bool        SpringVector::is_close(char c) { return  (c == '{' || c == '['); }
bool        SpringVector::is_brace(char c) { return  (c == '{' || c == '}'); }
bool        SpringVector::is_bracket(char c) { return  (c == '[' || c == ']'); }

bool        SpringVector::matching(char a, char b)
{ 
    bool braces = (a == '{' && b == '}') || (a == '}' && b == '{') 
    bool brackets = (a == '[' && b == ']') || (a == ']' && b == '[') 

    return  (braces || brackets); 
}

