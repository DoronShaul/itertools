#pragma once
#include <iostream>
#include <iterator>
using namespace std;

namespace itertools
{
template <class T, class U>
class product
{
private:
    T first;
    U second;

public:
    product(const T a, const U b)
    {
        this->first = a;
        this->second = b;
    }

    class iterator
    {
    private:
        T one;
        U two;

    public:
        iterator(T a, U b)
        {
            one = a;
            two = b;
        }

        
    };
    auto begin(){return first.begin();}
    auto end(){return first.begin();}
};
} // namespace itertools