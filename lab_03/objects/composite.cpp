#include "composite.h"

Composite::Composite(std::shared_ptr<Object> &element)
{
    _elements.push_back(element);
    _center = this->getCenter();
}


Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector)
{
    _elements = vector;
    _center = this->getCenter();
}


bool Composite::add(const std::shared_ptr<Object> &element)
{
    _elements.push_back(element);
    updateCenter();

    return true;
}


bool Composite::remove(const Iterator &iter)
{
    _elements.erase(iter);
    updateCenter();

    return true;
}

void Composite::updateCenter()
{
    _center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _elements)
    {
        _center = _center + element->getCenter();
        count++;
    }

    _center = Vertex(_center.getX() / count,
                    _center.getY() / count,
                    _center.getZ() / count);
}

bool Composite::isVisible()
{
    return false;
}

bool Composite::isComposite()
{
    return true;
}

Vertex Composite::getCenter() const
{
    return _center;
}

void Composite::moveElemsToOrigin()
{
    Vertex diff = _center - Vertex(0, 0, 0);

    Matrix<double> mtr = {{1,  0,  0,  diff.getX()},
                          {0,  1,  0,  diff.getY()},
                          {0,  0,  1,  diff.getZ()},
                          {0,  0,  0,      1      }};

    transformElems(mtr);
}

void Composite::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - _center;

    Matrix<double> mtr = {{1,  0,  0,  diff.getX()},
                          {0,  1,  0,  diff.getY()},
                          {0,  0,  1,  diff.getZ()},
                          {0,  0,  0,      1      }};

    transformElems(mtr);
}

void Composite::transformElems(const Matrix<double> &mtr)
{
    updateCenter();

    for (const auto &element : _elements)
    {
        element->transform(mtr);
    }

    _center.transform(mtr);
}

void Composite::transform(const Matrix<double> &mtr)
{
    updateCenter();
    _center.transform(mtr);
    Vertex new_center = _center;
    moveElemsToOrigin();

    for (const auto &element : _elements)
    {
        element->transform(mtr);
    }

    moveElemsToCenter(new_center);
}

Iterator Composite::begin()
{
    return _elements.begin();
}


Iterator Composite::end()
{
    return _elements.end();
}
