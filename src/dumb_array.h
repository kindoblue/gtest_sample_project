//
// Created by Stefano Secondo on 07/09/2017.
//

#ifndef SOUNDEX_DUMB_ARRAY_H
#define SOUNDEX_DUMB_ARRAY_H

#include <algorithm>
#include <cstddef>

class dumb_array {

public:
    // (default) constructor
    dumb_array(std::size_t size = 0)
            : mSize(size),
              mArray(mSize ? new int[mSize]() : nullptr)
    {
    }

    // copy-constructor
    dumb_array(const dumb_array& other)
            : mSize(other.mSize),
              mArray(mSize ? new int[mSize] : nullptr)
    {
        // note that this is non-throwing, because of the data
        // types being used; more attention to detail with regards
        // to exceptions must be given in a more general case, however
        std::copy(other.mArray, other.mArray + mSize, mArray);
    }

    // move constructor
    dumb_array(dumb_array&& other)
            : dumb_array() // initialize via default constructor, C++11 only
    {
        swap(*this, other);
    }


    // assignment and move assignment implemented with only one
    // method (copy and swap idiom)

    dumb_array& operator=(dumb_array other)
    {
        swap(*this, other);

        return *this;
    }

    // destructor
    ~dumb_array()
    {
        delete [] mArray;
    }

    friend void swap(dumb_array& first, dumb_array& second) // nothrow
    {
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.mSize, second.mSize);
        swap(first.mArray, second.mArray);
    }

private:
    std::size_t mSize;
    int* mArray;

};


#endif //SOUNDEX_DUMB_ARRAY_H
