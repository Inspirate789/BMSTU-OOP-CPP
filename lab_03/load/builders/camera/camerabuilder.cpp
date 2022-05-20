#include "camerabuilder.h"

void CameraBuilder::build()
{
    _camera = std::make_shared<Camera>();
}

void CameraBuilder::buildLocation(const Vertex &location)
{
    _camera = std::make_shared<Camera>(Camera(location));
}

bool CameraBuilder::isBuild() const
{
    return nullptr != _camera;
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return _camera;
}
