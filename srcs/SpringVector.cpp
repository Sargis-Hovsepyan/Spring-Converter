#include "SpringVector.hpp"
#include <stdexcept>
#include <iostream>

/* Constructors and Destructor */

SpringVector::SpringVector() {}

SpringVector::SpringVector(const SpringVector& other) { (void) other; }

SpringVector::~SpringVector() {}


/* Static Functions */

Spring&      SpringVector::equivalent_spring(string expr)
{
    stack<pair<char, int>>      stack;
    vector<pair<float, int>>    storage;

    expr = process(expr);
    stack.push(std::make_pair(expr[0], 0));

    for (unsigned long i = 1; i < expr.size(); i++)
    {
        pair<char, int> top = stack.top();
        char curr = expr[i];

        if (matching(top.first, curr))
        {
            add_springs(storage, top);
            stack.pop();
        }
        else if (is_open(curr))
            stack.push(std::make_pair(curr, i));
        else if (curr == '1')
            storage.push_back(std::make_pair(1, top.second));
        else
            throw std::invalid_argument("Invalid argument");
    }

    return *(new Spring(storage[0].first));
}


/* UTIL FUNCTIONS */

bool        SpringVector::is_open(char c) { return  (c == '{' || c == '['); }
bool        SpringVector::is_close(char c) { return  (c == '}' || c == ']'); }
bool        SpringVector::is_brace(char c) { return  (c == '{' || c == '}'); }
bool        SpringVector::is_bracket(char c) { return  (c == '[' || c == ']'); }

bool        SpringVector::matching(char a, char b)
{ 
    bool braces = (a == '{' && b == '}');
    bool brackets = (a == '[' && b == ']'); 

    return  (braces || brackets); 
}

string      SpringVector::process(const string& expr, bool unit)
{   
    stringstream    ss;
    unsigned long   i = 0;
    unsigned long   j = 0;

    while (i < expr.length() - 1)
    {
        if (matching(expr[i], expr[i+1]))
        {
            ss << ((unit) ? 1 : j++);
            i += 2;
        }
        else
            ss << expr[i++];
    }

    ss << expr[i];
    return ss.str();
}

void        SpringVector::add_springs(vector<pair<float, int>>& storage, pair<char, int> top)
{
    unsigned long   size = storage.size();
    unsigned long   j = size - 1;

    while (j > 0)
    {
        if (storage[j-1].second != storage[j].second)
            break;

        if (is_brace(top.first))
            storage[j-1].first = (storage[j].first * storage[j-1].first) / (storage[j].first + storage[j-1].first);
        else if (is_bracket(top.first))
            storage[j-1].first = (storage[j].first + storage[j-1].first);

        storage.erase(storage.begin() + j);
        j--;
    }

    if (j > 0)
        storage[j].second = storage[j-1].second;
}
