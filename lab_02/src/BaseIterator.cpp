#include "BaseIterator.h"

BaseIterator::BaseIterator()
{
    index = 0;
    size = 0;
}

BaseIterator::BaseIterator(const BaseIterator &iterator)
{
    index = iterator.index;
    size = iterator.size;
}

BaseIterator::~BaseIterator() = default;
