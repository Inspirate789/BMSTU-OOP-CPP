#include <QDebug>

#include "cameracommand.h"
#include "camera.h"
#include "solution.h"
#include "crcreator.h"
#include "scenemanager.h"
#include "transformmanager.h"

AddCamera::AddCamera(const ID & id, const double x, const double y, const double z) :
    _x(x), _y(y), _z(z), _id(id) {}

void AddCamera::execute()
{
    Vertex location(_x, _y, _z);

    std::shared_ptr<Camera> camera(new Camera(location));

    shared_ptr<Solution<SceneManager>> solution(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution->registration(2, &CrCreator<SceneManager>::createProdCreator);
    //shared_ptr<ManagerCreator<SceneManager>> cr(solution->create(2));
    //unique_ptr<SceneManager> sceneManagerPtr = solution->create(2)->createManager();
    //auto sceneManager = SceneManagerCreator().createManager();
    solution->create(2)->getScene()->addObject(camera);

    (*_id) = camera->getId();
};


DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    shared_ptr<Solution<SceneManager>> solution(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution->create(2)->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


MoveCamera::MoveCamera(const double dx, const double dy, const size_t id) :
    _dx(dx), _dy(dy), _id(id) {}

void MoveCamera::execute()
{
    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution_scene->create(2)->getScene();

    auto camIt = scene->getObject(_id);
    auto camera = *camIt;

    shared_ptr<Solution<TransformManager>> solution_transform(new Solution<TransformManager>({ {3, &CrCreator<TransformManager>::createProdCreator} }));
    solution_transform->registration(4, &CrCreator<TransformManager>::createProdCreator);

    solution_transform->create(4)->moveObject(camera, _dx, _dy, 0);
}


SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    shared_ptr<Solution<SceneManager>> solution(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution->registration(2, &CrCreator<SceneManager>::createProdCreator);
    solution->create(2)->setCamera(_id);
}
