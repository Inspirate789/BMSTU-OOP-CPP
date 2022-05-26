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

    virtual Vertex getCenter() const override;
    void transform(const Matrix<double> &mtr, const Vertex &center) override;
private:
    Vertex _location;
};


#endif //CAMERA_H
