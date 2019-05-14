#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename T, typename U>
class productIterator
{

private:
    const pair<T, U> firstPair; 
    const pair<T, U> secondPair;

public:
    productIterator(pair<T, U> &a, pair<T, U> &b) : firstPair(a), secondPair(b) {}

    class iterator
    {
    private:
        pair<T, U> firstPair;
        pair<U, U> secondPair;

    public:
        iterator(pair<T, U> a, pair<U, U> b) : firstPair(a), secondPair(b) {}

        pair<T, U> &operator*()
        {
            return firstPair;
        }

        bool operator==(const iterator &ot) const
        {
            return firstPair.first == ot.firstPair.first;
        }

        bool operator!=(const iterator &ot) const
        {
            return firstPair.first != ot.firstPair.first;
        }

        iterator &operator=(const iterator &ot)
        {
            this->firstPair.first = ot.firstPair.first;
            this->firstPair.second = ot.firstPair.second;
            this->secondPair.first = ot.secondPair.first;
            this->secondPair.second = ot.secondPair.second;
            return *this;
        }

        iterator &operator++()
        {
            firstPair.second++;
            if (firstPair.second == secondPair.second)
            {
                firstPair.first++;
                firstPair.second = secondPair.first;
            }
            return *this;
        }

        const iterator operator++(int)
        {
            iterator temp = *this;
            firstPair.second++;
            if (firstPair.second == secondPair.second)
            {
                firstPair.first++;
                firstPair.second = secondPair.first;
            }
            return temp;
        }
    };

public:
    auto begin()
    {
        return iterator{firstPair, pair<U, U>(firstPair.second, secondPair.second)};
    }

    auto end()
    {
        return iterator{pair<T, U>(secondPair.first, secondPair.second), pair<U, U>(firstPair.second, secondPair.second)};
    }
};

template <typename T, typename U>
auto product(T firstProd, U secondProd)
{
    pair<decltype(firstProd.begin()), decltype(secondProd.begin())> firstPair(firstProd.begin(), secondProd.begin());
    pair<decltype(firstProd.end()), decltype(secondProd.end())> secondPair(firstProd.end(), secondProd.end());

    return productIterator<decltype(firstProd.begin()), decltype(secondProd.begin())>(firstPair, secondPair);
}

} // namespace itertools