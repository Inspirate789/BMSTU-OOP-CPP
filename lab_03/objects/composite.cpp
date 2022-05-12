#include "composite.h"

Composite::Composite(std::shared_ptr<Object> &element)
{
    _elements.push_back(element);
}


Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector)
{
    _elements = vector;
}


bool Composite::add(const std::shared_ptr<Object> &element)
{
    _elements.push_back(element);

    return true;
}


bool Composite::remove(const Iterator &iter)
{
    _elements.erase(iter);

    return true;
}


bool Composite::isVisible()
{
    return false;
}

bool Composite::isComposite()
{
    return true;
}


void Composite::transform(const Vertex &move, const Vertex &scale, const Vertex &rotate)
{
    for (const auto &element : _elements)
    {
        element->transform(move, scale, rotate);
    }
}


Iterator Composite::begin()
{
    return _elements.begin();
}


Iterator Composite::end()
{
    return _elements.end();
}
