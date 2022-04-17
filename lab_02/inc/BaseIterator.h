#ifndef _BASE_ITERATOR_H_
#define _BASE_ITERATOR_H_

#include <cstdlib>

class BaseIterator
{
protected:
    int index = 0;       // size_t?
    int elems_count = 0; // size_t?

public:
    BaseIterator();
    BaseIterator(BaseIterator &iterator);
    virtual ~BaseIterator() = 0;
};

#endif
