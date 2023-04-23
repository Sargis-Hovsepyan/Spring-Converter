#include "SpringVector.hpp"

/* Constructors and Destructor */

SpringVector::SpringVector() {}

SpringVector::SpringVector(const SpringVector& other) { (void) other; }

SpringVector::~SpringVector() {}


/* Static Functions */

Spring&      SpringVector::equivalent_spring(string expr)
{
    stack<pair<char, int>>      stack;
    vector<pair<float, int>>    storage;

    stack.push(std::make_pair(expr[0], 0));

    for (unsigned long i = 1; i < expr.size(); i++)
    {
        pair<char, int> top = stack.top();
        pair<char, int> curr = std::make_pair(expr[i], i);

        if (matching(top.first, curr.first))
        {
            stack.pop();
            if (curr.second - top.second == 1)
                storage.push_back(std::make_pair(1, stack.top().second));
            else
                add_springs(storage, top);
        }
        else if (is_open(curr.first))
            stack.push(curr);
        else
            throw std::invalid_argument("Invalid argument format!");
    }

    return *(new Spring(storage[0].first));
}

Spring&      SpringVector::equivalent_spring(string expr, vector<Spring>& springs)
{
    stack<pair<char, int>>      stack;
    vector<pair<float, int>>    storage;
    unsigned long               j = 0;

    stack.push(std::make_pair(expr[0], 0));

    for (unsigned long i = 1; i < expr.size(); i++)
    {
        pair<char, int> top = stack.top();
        pair<char, int> curr = std::make_pair(expr[i], i);

        if (matching(top.first, curr.first))
        {
            stack.pop();
            if (curr.second - top.second == 1)
            {
                if (j >= springs.size())
                    throw std::invalid_argument("Invalid number of springs!");

                storage.push_back(std::make_pair(springs[j++].get_k(), stack.top().second));
            }
            else
                add_springs(storage, top);
        }
        else if (is_open(curr.first))
            stack.push(curr);
        else
            throw std::invalid_argument("Invalid argument format!");
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
