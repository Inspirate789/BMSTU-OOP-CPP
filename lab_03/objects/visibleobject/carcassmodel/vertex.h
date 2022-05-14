#ifndef VERTEX_H
#define VERTEX_H

#include "matrix.h"

class Vertex
{
public:
    Vertex() = default;
    Vertex(const double x, const double y, const double z);

    Vertex(const Vertex &vertex) = default;
    Vertex(const Vertex &&vertex) noexcept;

    Vertex &operator=(const Vertex &vertex) = default;
    Vertex &operator=(Vertex &&vertex) noexcept;

    ~Vertex() = default;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double const x);
    void setY(double const y);
    void setZ(double const z);

    bool operator==(const Vertex &vertex) const noexcept;
    bool isEqual(const Vertex &vertex) const noexcept;

    bool operator!=(const Vertex &vertex) const noexcept;
    bool isNotEqual(const Vertex &vertex) const noexcept;

    Vertex operator+(const Vertex &vertex);
    Vertex operator-(const Vertex &vertex);

    Vertex getAbsVertex(const Vertex &center);

    void transform(const Matrix<double> &mtr);

private:
    double _x;
    double _y;
    double _z;
};

#endif // VERTEX_H
