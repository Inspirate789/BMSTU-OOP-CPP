#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"
#include "drawcarcassmodeladapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(const Vertex &location) : _location(location) { }
    ~Camera() override = default;

    void transform(const Vertex &move, const Vertex &scale, const Vertex &rotate) override;
private:
    void moveX(const double dx);
    void moveY(const double dy);
    void moveZ(const double dz);

    Vertex _location;
};


#endif //CAMERA_H
