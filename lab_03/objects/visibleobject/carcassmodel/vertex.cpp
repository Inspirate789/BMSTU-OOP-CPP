#include <cmath>

#include "vertex.h"

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Vertex::Vertex(const double x, const double y, const double z)
{
    setX(x);
    setY(y);
    setZ(z);
}


Vertex::Vertex(const Vertex &&vertex) noexcept
{
    setX(vertex._x);
    setY(vertex._y);
    setZ(vertex._z);

    vertex.~Vertex();
}


Vertex &Vertex::operator=(Vertex &&vertex) noexcept
{
    setX(vertex._x);
    setY(vertex._y);
    setZ(vertex._z);

    vertex.~Vertex();

    return *this;
}

double Vertex::getX() const
{
    return _x;
}

double Vertex::getY() const
{
    return _y;
}

double Vertex::getZ() const
{
    return _z;
}

void Vertex::setX(const double x)
{
    _x = x;
}

void Vertex::setY(const double y)
{
    _y = y;
}

void Vertex::setZ(const double z)
{
    _z = z;
}

bool Vertex::operator==(const Vertex &vertex) const noexcept
{
    return (vertex._x == _x) && (vertex._y == _y) && (vertex._z == _z);
}

bool Vertex::isEqual(const Vertex &vertex) const noexcept
{
    return *this == vertex;
}

bool Vertex::operator!=(const Vertex &vertex) const noexcept
{
    return !(*this == vertex);
}

bool Vertex::isNotEqual(const Vertex &vertex) const noexcept
{
    return !(*this == vertex);
}

Vertex Vertex::operator+(const Vertex &vertex) const
{
    Vertex d{*this};

    d.setX(d._x + vertex._x);
    d.setY(d._y + vertex._y);
    d.setZ(d._z + vertex._z);

    return d;
}

Vertex Vertex::operator-(const Vertex &vertex) const
{
    Vertex d{*this};

    d.setX(d._x - vertex._x);
    d.setY(d._y - vertex._y);
    d.setZ(d._z - vertex._z);

    return d;
}


void Vertex::transform(const Matrix<double> &mtr)
{
    Matrix<double> cur_location = {{_x, _y, _z, 1}};
    Matrix<double> new_location = cur_location * mtr;

    _x = new_location[0][0];
    _y = new_location[0][1];
    _z = new_location[0][2];
}

Vertex Vertex::getCenter() const
{
    return *this;
}

Vertex Vertex::getAbsVertex(const Vertex &center)
{
    return (*this) + center;
}
