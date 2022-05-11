#include "link.h"

Link::Link(const std::size_t firstVertex, const std::size_t secondVertex)
{
    setFirst(firstVertex);
    setSecond(secondVertex);
}

std::size_t Link::getFirst() const
{
    return _first;
}

std::size_t Link::getSecond() const
{
    return _second;
}

void Link::setFirst(const std::size_t index)
{
    _first = index;
}

void Link::setSecond(const std::size_t index)
{
    _second = index;
}
