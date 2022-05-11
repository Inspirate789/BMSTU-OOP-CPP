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

Vertex Vertex::operator+(const Vertex &vertex)
{
    Vertex d{*this};

    d.setX(d._x + vertex._x);
    d.setY(d._y + vertex._y);
    d.setZ(d._z + vertex._z);

    return d;
}

Vertex Vertex::operator-(const Vertex &vertex)
{
    Vertex d{*this};

    d.setX(d._x - vertex._x);
    d.setY(d._y - vertex._y);
    d.setZ(d._z - vertex._z);

    return d;
}


void Vertex::move(const double dx, const double dy, const double dz)
{
    setX(_x + dx);
    setY(_y + dy);
    setZ(_y + dz);
}

void Vertex::scale(const double kx, const double ky, const double kz)
{
    setX(_x * kx);
    setY(_y * ky);
    setZ(_z * kz);
}

void Vertex::rotate(const double ox, const double oy, const double oz)
{
    rotateX(ox);
    rotateY(oy);
    rotateZ(oz);
}


void Vertex::rotateX(const double ox)
{
    const double cosO = cos(toRadians(ox));
    const double sinO = sin(toRadians(ox));

    const double tmp = _y;

    setY(_y * cosO + _z * sinO);
    setZ(_z * cosO - tmp * sinO);
}


void Vertex::rotateY(const double oy)
{
    const double cosO = cos(toRadians(oy));
    const double sinO = sin(toRadians(oy));

    const double tmp = _x;

    setX(_x * cosO + _z * sinO);
    setZ(_z * cosO - tmp * sinO);
}


void Vertex::rotateZ(const double oz)
{
    const double cosO = cos(toRadians(oz));
    const double sinO = sin(toRadians(oz));

    const double tmp = _x;

    setX(_x * cosO + _y * sinO);
    setY(_y * cosO - tmp * sinO);
}

Vertex Vertex::getAbsVertex(const Vertex &center)
{
    return (*this) + center;
}
