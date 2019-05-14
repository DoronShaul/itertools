#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class zipIterator
{

private:
    pair<T,U> firstPair;
    pair<T,U> secondPair;

public:
    zipIterator(pair<T, U> &a, pair<T, U> &b) : firstPair(a), secondPair(b) {}

    class iterator
    {
    private:
        pair<T, U> zipIt;

    public:
        iterator(pair<T, U> &otherIt) : zipIt(otherIt) {}

        pair<T, U> &operator*()
        {
            return zipIt;
        }
        bool operator==(const iterator &ot) const
        {
            return zipIt.first == ot.zipIt.first;
        }
        bool operator!=(const iterator &ot) const
        {
            return zipIt.first != ot.zipIt.first;
        }
        iterator &operator=(const iterator &ot)
        {
            this->zipIt.first = ot.zipIt.first;
            this->zipIt.second = ot.zipIt.second;
            return *this;
        }
        iterator &operator++() //postfix
        {
            zipIt.first++;
            zipIt.second++;
            return *this;
        }
        const iterator operator++(int) //prefix
        {
            iterator tmp = *this;
            zipIt.first++;
            zipIt.second++;
            return tmp;
        }
    };

public:
    auto begin()
    {
        return iterator{firstPair};
    }
    auto end()
    {
        return iterator{secondPair};
    }
};

template <typename T, typename U>
auto zip(T first, U second)
{
    std::pair<decltype(first.begin()), decltype(second.begin())> firstPair(first.begin(), second.begin());
    std::pair<decltype(first.end()), decltype(second.end())> secondPair(first.end(), second.end());
    return zipIterator<decltype(first.begin()), decltype(second.begin())>(firstPair, secondPair);
}

} // namespace itertools

template <typename T, typename U>
ostream &operator<<(ostream &os, std::pair<T, U> &a)
{
    os << *a.first << "," << *a.second;
    return os;
}