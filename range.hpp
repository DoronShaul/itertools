#pragma once

namespace itertools
{

template <typename T>
class rangeIterator
{
private:
    const T start;
    const T last;

public:
    rangeIterator(const T &a, const T &b) : start(a), last(b){};
    

    class iterator
    {
    private:
        T rangePtr;

    public:
        iterator(T rangePtr)
        {
            this->rangePtr = rangePtr;
        }

        T &operator*()
        {
            return rangePtr;
        }
        bool operator!=(const iterator &ot) const
        {
            return rangePtr != ot.rangePtr;
        }
        bool operator==(const iterator &ot) const
        {
            return rangePtr == ot.rangePtr;
        }
        iterator &operator=(const iterator &ot)
        {
            rangePtr = ot.rangePtr;
            return *this;
        }

        iterator &operator++() //postfix
        {
            rangePtr++;
            return *this;
        }

        const iterator operator++(int) //prefix
        {
            iterator tmp = *this;
            rangePtr++;
            return tmp;
        }
    };

    iterator begin() const
    {
        return iterator{start};
    }

    iterator end() const
    {
        return iterator{last};
    }
};

template <typename T>
rangeIterator<T> range(T s, T e)
{
    return rangeIterator<T>(s, e);
}

} // namespace itertools