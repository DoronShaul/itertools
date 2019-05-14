#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T>
class powersetIterator
{
private:
    const T powerSet;

public:
    powersetIterator(const T &a) : powerSet(a) {}

    class iterator
    {
        pair<T, uint> powerIt;

    public:
        iterator(pair<T, uint> it) : powerIt(it) {}

        pair<T, uint> &operator*()
        {
            return powerIt;
        }

        bool operator==(const iterator &other) const
        {
            return powerIt.second == other.powerIt.second;
        }
        bool operator!=(const iterator &other) const
        {
            return powerIt.second != other.powerIt.second;
        }
        iterator &operator=(const iterator &other)
        {
            powerIt.first = other.powerIt.first;
            powerIt.second = other.powerIt.second;
            return *this;
        }
        iterator &operator++() //postfix
        {
            powerIt.second++;
            return *this;
        }
        const iterator operator++(int) //prefix
        {
            iterator temp = *this;
            powerIt.second++;
            return temp;
        }
    };

public:
    auto begin() const
    {
        return iterator{pair<T, uint>(powerSet, 0)};
    }
    auto end() const
    {
        auto powerIter = powerSet.begin();
        int i = 1;
        while (powerIter != powerSet.end())
        {
            i = i << 1;
            powerIter++;
        }
        return iterator{pair<T, uint>(powerSet, i)};
    }
};

template <typename T>
auto powerset(T power)
{
    return powersetIterator<T>(power);
}

} // namespace itertools

// insert to ostream the correct set by bits
template <typename T>
ostream &operator<<(ostream &os, pair<T, uint> &pow)
{
    os << "{";
    auto first = pow.first.begin();
    auto last = pow.first.end();
    int i = 1;
    bool isFirst = true;
    while (first != last)
    {
        if (i & pow.second)
        {
            if (!isFirst)
                os << ",";

            os << *first;
            isFirst = false;
        }
        first++;
        i = i << 1;
    }
    os << "}";
    return os;
}