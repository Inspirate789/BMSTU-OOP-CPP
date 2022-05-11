#include <QDebug>

#include "modelcommand.h"
#include "solution.h"
#include "crcreator.h"
#include "scenemanager.h"
#include "transformmanager.h"
#include "loadmanager.h"
#include "modelloadmoderator.h"

MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) { }


void MoveModel::execute()
{
    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution_scene->create(2)->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;

    shared_ptr<Solution<TransformManager>> solution_transform(new Solution<TransformManager>({ {1, &CrCreator<TransformManager>::createProdCreator} }));
    solution_transform->registration(2, &CrCreator<TransformManager>::createProdCreator);

    solution_transform->create(2)->moveObject(model, _dx, _dy, _dz);
}


ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id) :
    _kx(kx), _ky(ky), _kz(kz), _id(id) { }

void ScaleModel::execute()
{
    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution_scene->create(2)->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;

    shared_ptr<Solution<TransformManager>> solution_transform(new Solution<TransformManager>({ {1, &CrCreator<TransformManager>::createProdCreator} }));
    solution_transform->registration(2, &CrCreator<TransformManager>::createProdCreator);

    solution_transform->create(2)->scaleObject(model, _kx, _ky, _kz);
}


RotateModel::RotateModel(const double ox, const double oy,
                         const double oz, const std::size_t id) :
        _ox(ox), _oy(oy), _oz(oz), _id(id) { }

void RotateModel::execute()
{
    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution_scene->create(2)->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;

    shared_ptr<Solution<TransformManager>> solution_transform(new Solution<TransformManager>({ {1, &CrCreator<TransformManager>::createProdCreator} }));
    solution_transform->registration(2, &CrCreator<TransformManager>::createProdCreator);

    solution_transform->create(2)->rotateObject(model, _ox, _oy, _oz);
}


TransformModel::TransformModel(const Vertex &move, const Vertex &scale,
                               const Vertex &rotate, const std::size_t id) :
    _move(move), _scale(scale), _rotate(rotate), _id(id) { }

void TransformModel::execute()
{
    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution_scene->create(2)->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;

    shared_ptr<Solution<TransformManager>> solution_transform(new Solution<TransformManager>({ {1, &CrCreator<TransformManager>::createProdCreator} }));
    solution_transform->registration(2, &CrCreator<TransformManager>::createProdCreator);

    solution_transform->create(2)->transformObject(model, _move, _scale, _rotate);
}


DeleteModel::DeleteModel(const std::size_t id) : _id(id) { }

void DeleteModel::execute()
{
    shared_ptr<Solution<SceneManager>> solution(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto scene = solution->create(2)->getScene();

    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


LoadModel::LoadModel(const ID &id, std::string &fileName) : _fileName(fileName), _id(id) { }

void LoadModel::execute()
{
    shared_ptr<Solution<ModelLoadModerator>> solution_mod(new Solution<ModelLoadModerator>({ {1, &CrCreator<ModelLoadModerator>::createProdCreator} }));
    solution_mod->registration(2, &CrCreator<ModelLoadModerator>::createProdCreator);
    auto moderator = solution_mod->create(2);

    shared_ptr<Solution<LoadManager>> solution_load(new Solution<LoadManager>({ {1, &CrCreator<LoadManager>::createProdCreator} }));
    solution_load->registration(2, &CrCreator<LoadManager>::createProdCreator);
    auto manager = solution_load->create(2);

    manager->setLoader(moderator);
    auto model = manager->load(_fileName);

    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);

    solution_scene->create(2)->getScene()->addObject(model);

    (*_id) = model->getId();
}
