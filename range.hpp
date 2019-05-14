#pragma once
#include <iostream>
#include <iterator>

namespace itertools
{
template <typename T>
class range
{
private:
    T start;
    T last;

public:
    range()
    {
        this->start = 0;
        this->last = 0;
    }

    range(T a, T b)
    {
        this->start = a;
        this->last = b;
    }
    class iterator;
    iterator begin() { return iterator(this->start); }
    iterator end() { return iterator(this->last); }

    class iterator
    {
    private:
        T rangeValue;

    public:
        /*typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::input_iterator_tag iterator_category;
        */

        explicit iterator(T value) { rangeValue = value; }
        T& operator*() { return rangeValue; }
        bool operator==(const iterator &other) const { return rangeValue == other.rangeValue; }
        bool operator!=(const iterator &other) const { return !(*this == other); }
        iterator &operator++(int)
        {
            iterator temp(rangeValue);
            ++(*this);
            return temp;
        }
        iterator &operator++()
        {
            ++rangeValue;
            return *this;
        }
    };
};

} // namespace itertools
