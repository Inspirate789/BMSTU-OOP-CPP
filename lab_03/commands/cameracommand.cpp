#include <QDebug>

#include "cameracommand.h"
#include "camera.h"
#include "managersolution.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

AddCamera::AddCamera(const ID & id, const double x, const double y, const double z) :
    _x(x), _y(y), _z(z), _id(id) {}

void AddCamera::execute()
{
    Vertex location(_x, _y, _z);

    std::shared_ptr<Camera> camera(new Camera(location));

    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    sceneManager->getScene()->addObject(camera);

    (*_id) = camera->getId();
};


DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    auto scene = ManagerSolution<SceneManagerCreator>().create()->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


MoveCamera::MoveCamera(const double dx, const double dy, const size_t id) :
    _dx(dx), _dy(dy), _id(id) {}

void MoveCamera::execute()
{
    auto scene = ManagerSolution<SceneManagerCreator>().create()->getScene();

    auto camIt = scene->getObject(_id);
    auto camera = *camIt;
    ManagerSolution<TransformManagerCreator>().create()->moveObject(camera, _dx, _dy, 0);
}


SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    ManagerSolution<SceneManagerCreator>().create()->setCamera(_id);
}
