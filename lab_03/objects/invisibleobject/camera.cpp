#include "camera.h"

void Camera::transform(const Matrix<double> &mtr)
{
    Matrix<double> cur_location = {{_location.getX()}, {_location.getY()}, {_location.getZ()}, {1}};
    Matrix<double> new_location = mtr * cur_location;

    _location = Vertex(new_location[0][0], new_location[1][0], new_location[2][0]);
}

Vertex Camera::getCenter() const
{
    return _location;
}
