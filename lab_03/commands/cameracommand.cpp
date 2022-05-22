#include <QDebug>

#include "cameracommand.h"

AddCamera::AddCamera(const ID &id, const Vertex &location) :
    _id(id), _location(location) {}

void AddCamera::execute()
{
    //_scene->addCamera(_location);
    (*_id) = _scene->addCamera(_location);
};



DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    Iterator objIt = _scene->getObjectIter(_id);
    _scene->deleteObject(objIt);
}



MoveCamera::MoveCamera(const double dx, const double dy, const double dz, const size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) {}

void MoveCamera::execute()
{
    auto camera = _scene->getObject(_id);
    _transformManager->moveObject(camera, _dx, _dy, _dz);
}



SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    _sceneManager->setCamera(_id);
}
