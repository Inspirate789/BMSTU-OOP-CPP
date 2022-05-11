#include "transformmanager.h"

void TransformManager::moveObject(const std::shared_ptr <Object> &object,
                                  const double &dx,
                                  const double &dy,
                                  const double &dz)
{
    Vertex move(dx, dy, dz);
    Vertex scale(1, 1, 1);
    Vertex rotate(0, 0, 0);

    object->transform(move, scale, rotate);
}


void TransformManager::scaleObject(const std::shared_ptr <Object> &object,
                                   const double &kx,
                                   const double &ky,
                                   const double &kz)
{
    Vertex move(0, 0, 0);
    Vertex scale(kx, ky, kz);
    Vertex rotate(0, 0, 0);

    object->transform(move, scale, rotate);
}


void TransformManager::rotateObject(const std::shared_ptr <Object> &object,
                                   const double &ox,
                                   const double &oy,
                                   const double &oz)
{
    Vertex move(0, 0, 0);
    Vertex scale(1, 1, 1);
    Vertex rotate(ox, oy, oz);

    object->transform(move, scale, rotate);
}


void TransformManager::transformObject(const std::shared_ptr<Object> &object,
                                       const Vertex &move,
                                       const Vertex &scale,
                                       const Vertex &rotate)
{
    object->transform(move, scale, rotate);
}
