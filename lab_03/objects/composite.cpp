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


void Composite::transform(const Matrix<double> &mtr)
{
    Vertex center = this->getCenter();

    std::vector<Vertex> distances;

    for (const auto &element : _elements)
    {
        distances.push_back(element->getCenter() - center);
    }

    center.transform(mtr);

    size_t i = 0;
    for (const auto &element : _elements)
    {
        Matrix<double> move_mtr = {{1,  0,  0,  0},
                                   {0,  1,  0,  0},
                                   {0,  0,  1,  0},
                                   {distances[i].getX(), distances[i].getY(), distances[i].getZ(), 1}};
        element->transform(move_mtr);
        i++;
    }

    for (const auto &element : _elements)
    {
        element->transform(mtr);
    }
}

Vertex Composite::getCenter() const
{
    Vertex center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _elements)
    {
        center = center + element->getCenter();
        count++;
    }

    center = Vertex(center.getX() / count, center.getY() / count, center.getZ() / count);

    return center;
}


Iterator Composite::begin()
{
    return _elements.begin();
}


Iterator Composite::end()
{
    return _elements.end();
}
