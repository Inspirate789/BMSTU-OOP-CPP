#include "BaseIterator.h"

BaseIterator::BaseIterator()
{
    index = 0;
    elems_count = 0;
}

BaseIterator::BaseIterator(BaseIterator &iterator)
{
    index = iterator.index;
    elems_count = iterator.elems_count;
}

BaseIterator::~BaseIterator() = default;
