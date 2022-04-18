#ifndef _BASE_ITERATOR_H_
#define _BASE_ITERATOR_H_

#include <cstdlib>

class BaseIterator
{
public:
    BaseIterator();
    BaseIterator(const BaseIterator &iterator);
    virtual ~BaseIterator() = 0;

protected:
    size_t index = 0;
    size_t size = 0;
};

#endif
