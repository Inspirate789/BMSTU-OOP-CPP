#include "camera.h"

void Camera::transform(const Matrix<double> &mtr, const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    _location = _location + diff;

    Matrix<double> cur_location = {{_location.getX(), _location.getY(), _location.getZ(), 1}};
    Matrix<double> new_location = cur_location * mtr;

    _location = Vertex(new_location[0][0], new_location[0][1], new_location[0][2]);

    _location = _location - diff;
}

Vertex Camera::getCenter() const
{
    return _location;
}
