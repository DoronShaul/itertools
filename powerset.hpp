#pragma once
#include <iostream>
#include <iterator>
using namespace std;

namespace itertools
{
template <class T>
class powerset
{
private:
    T first;

    class iterator
    {
    private:
        T one;

    public:
        iterator(T a)
        {
            one = a;
        }
    };

public:
    powerset() {first=NULL;}
    powerset(const T a)
    {
        first = a;
    }

    
    auto begin() { return first.begin(); }
    auto end() { return first.begin(); }
};
} // namespace itertools