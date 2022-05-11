#include "camerabuilder.h"

void CameraBuilder::build()
{
    _camera = std::make_shared<Camera>();
}

void CameraBuilder::buildLocation(const double x, const double y, const double z)
{
    _camera = std::make_shared<Camera>(Camera(Vertex(x, y, z)));
}

bool CameraBuilder::isBuild() const
{
    return nullptr != _camera;
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return _camera;
}
