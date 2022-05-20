#include <QDebug>

#include "cameracommand.h"

AddCamera::AddCamera(const ID & id,
                     const std::shared_ptr<Camera> camera,
                     const std::shared_ptr<SceneManager> sceneManager) :
    _id(id), _camera(camera), _sceneManager(sceneManager) {}

void AddCamera::execute()
{
    _sceneManager->getScene()->addObject(_camera);
    (*_id) = _camera->getId();
};


DeleteCamera::DeleteCamera(const std::size_t id,
                           const std::shared_ptr<SceneManager> sceneManager) :
    _id(id), _sceneManager(sceneManager) {}

void DeleteCamera::execute()
{
    auto scene = _sceneManager->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


MoveCamera::MoveCamera(const double dx, const double dy, const double dz,
                       const size_t id,
                       const std::shared_ptr<SceneManager> sceneManager,
                       const std::shared_ptr<TransformManager> transformManager) :
    _dx(dx), _dy(dy), _dz(dz), _id(id),
    _sceneManager(sceneManager), _transformManager(transformManager) {}

void MoveCamera::execute()
{
    auto scene = _sceneManager->getScene();

    auto camIt = scene->getObject(_id);
    auto camera = *camIt;
    _transformManager->moveObject(camera, _dx, _dy, _dz);
}


SetCamera::SetCamera(const std::size_t id,
                     const std::shared_ptr<SceneManager> sceneManager) :
    _id(id), _sceneManager(sceneManager) {}

void SetCamera::execute()
{
    _sceneManager->setCamera(_id);
}
