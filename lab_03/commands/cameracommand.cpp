#include <QDebug>

#include "cameracommand.h"

AddCamera::AddCamera(const ID & id, const Vertex &location) :
    _id(id), _location(location) {}

void AddCamera::execute()
{
    auto camera = std::make_shared<Camera>(Camera(_location));
    _sceneManager->getScene()->addObject(camera);
    (*_id) = camera->getId();
};


DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    auto scene = _sceneManager->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


MoveCamera::MoveCamera(const double dx, const double dy, const double dz, const size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) {}

void MoveCamera::execute()
{
    auto scene = _sceneManager->getScene();

    auto camIt = scene->getObject(_id);
    auto camera = *camIt;
    _transformManager->moveObject(camera, _dx, _dy, _dz);
}


SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    _sceneManager->setCamera(_id);
}
