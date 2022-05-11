#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "basemanager.h"
#include "object.h"


class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager &operator = (const TransformManager &manager) = delete;

    ~TransformManager() = default;

    static void moveObject(const std::shared_ptr<Object> &object,
                           const double &dx,
                           const double &dy,
                           const double &dz);
    static void scaleObject(const std::shared_ptr<Object> &object,
                            const double &kx,
                            const double &ky,
                            const double &kz);
    static void rotateObject(const std::shared_ptr<Object> &object,
                             const double &ox,
                             const double &oy,
                             const double &oz);

    static void transformObject(const std::shared_ptr<Object> &object,
                                const Vertex &move,
                                const Vertex &scale,
                                const Vertex &rotate);
};


#endif //TRANSFORMMANAGER_H
