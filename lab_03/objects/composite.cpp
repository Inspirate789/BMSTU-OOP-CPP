#include "composite.h"

Composite::Composite(std::shared_ptr<Object> &element)
{
    _elements.push_back(element);
    updateCenter();
}


Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector)
{
    _elements = vector;
    updateCenter();
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

void Composite::moveElemsToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mtr);
    updateCenter();
}

void Composite::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - _center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mtr);
    updateCenter();
}

void Composite::transformElems(const Matrix<double> &mtr)
{
    for (const auto &element : _elements)
    {
        element->updateCenter();
        element->transform(mtr, _center);
    }
}

void Composite::transform(const Matrix<double> &mtr, const Vertex &center)
{
    updateCenter();

    moveElemsToOrigin(center);
    transformElems(mtr);
    moveElemsToCenter(center);
}

Iterator Composite::begin()
{
    return _elements.begin();
}


Iterator Composite::end()
{
    return _elements.end();
}
