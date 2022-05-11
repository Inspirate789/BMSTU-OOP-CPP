#include "camera.h"

void Camera::moveX(const double dx)
{
    _location.setX(_location.getX() + dx);
}


void Camera::moveY(const double dy)
{
    _location.setY(_location.getY() + dy);
}


void Camera::moveZ(const double dz)
{
    _location.setZ(_location.getZ() + dz);
}


void Camera::transform(const Vertex &move, const Vertex &scale, const Vertex &rotate)
{
    moveX(move.getX());
    moveY(move.getY());
}


void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
