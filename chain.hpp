#pragma once
#include <iostream>
using namespace std;
namespace itertools
{
template <typename T, typename U>
class chainIterator
{

private:
    const pair<T,T> first;
    const pair<U,U> second;

public:
    chainIterator(pair<T,T> a, pair<U,U> b) : first(a), second(b){}

    class iterator
    {
    private:
        pair<T,T> firstPair;
        pair<U,U> secondPair;
        bool isFirst;

    public:
        iterator(pair<T,T> a, pair<U,U> b, bool isFirst) : firstPair(a), secondPair(b), isFirst(true){};

        auto &operator*()
        {
            if (isFirst == true)
                return *firstPair.first;
            return *secondPair.first;
        }

        bool operator==(const iterator &ot) const
        {
            if (isFirst == true)
                return firstPair.first == ot.firstPair.second;
            return secondPair.first == ot.secondPair.second;
        }

        

        iterator &operator=(const iterator &other)
        {
            firstPair = other.firstPair;
            secondPair = other.secondPair;
            isFirst = other.isFirst;
            return *this;
        }

        bool operator!=(const iterator &ot) const
        {

            if (isFirst == true)
                return firstPair.first != ot.firstPair.second;
            return secondPair.first != ot.secondPair.second;
        }
        iterator &operator++()
        {
            if (isFirst == true)
            {
                if (++firstPair.first == firstPair.second)
                    isFirst = false;

                return *this;
            }
            secondPair.first++;
            return *this;
        }
        const iterator operator++(int)
        {
            iterator temp = *this;
            if (isFirst)
            {
                if (++firstPair.first == firstPair.second)
                    isFirst = false;
                return *this;
            }
            secondPair.first++;
            return temp;
        }
    };
public:
    auto begin() const
    {
        return iterator{first, second, true};
    }

    auto end() const
    {
        return iterator{first, second, false};
    }
};

template <typename T, typename U>
auto chain(T first, U second)
{
    pair<decltype(first.begin()), decltype(first.end())> firstPair(first.begin(), first.end());
    pair<decltype(second.begin()), decltype(second.end())> secondPair(second.begin(), second.end());

    return chainIterator<decltype(first.begin()), decltype(second.begin())>(firstPair, secondPair);
}

} // namespace itertools