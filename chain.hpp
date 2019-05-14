#pragma once
#include <iostream>
//#include <iterator>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class chain
{
private:
    T first;
    U second;

public:
    chain(const T a, const U b)
    {
        this->first = a;
        this->second = b;
    }
    class iterator;
    iterator begin() { return iterator(first.begin(),first.end(),second.begin()); }
    iterator end() { return iterator(second.begin(), second.begin(), second.begin()); }

    class iterator
    {
    private:
        T tBegin;
        T tEnd;
        U uBegin;

    public:
        /*typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::input_iterator_tag iterator_category;
        */

        explicit iterator(T tBeg, T endT, U uBeg)
        {
            tBegin=tBeg;
            tEnd=endT;
            uBegin=uBeg;
        }

        typename chain<T,U> &operator*() const { return nullptr; }

        bool operator==(const iterator &other) const
        {
            if (tBegin == other.tBegin && tEnd == other.tEnd && uBegin == other.uBegin)
            {
                return true;
            }
            return false;
        }

        bool operator!=(const iterator &other) const { return !(*this == other); }

        iterator &operator++(int)
        {
            iterator temp(tBegin, tEnd, uBegin);
            ++(*this);
            return temp;
        }
        iterator &operator++()
        {
            ++(*this);
            return *this;
        }
    };
};
} // namespace itertools