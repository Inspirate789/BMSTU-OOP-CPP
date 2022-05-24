#include <iterator>

#include "scene.h"
#include "composite.h"

#include <QDebug>

Scene::Scene() : _objects(new Composite) { }

std::size_t Scene::addObject(const std::shared_ptr<Object> &object)
{
    _objects->add(object);

    return object->getId();
}

std::size_t Scene::addCamera(const Vertex &location)
{
    auto camera = std::make_shared<Camera>(Camera(location));

    return addObject(camera);
}

void Scene::deleteObject(Iterator &iter)
{
    _objects->remove(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    auto iter = begin();

    for (; iter != end() && (*iter)->getId() != id; ++iter);

    return iter;
}

std::shared_ptr<Object> Scene::getObject(const std::size_t id)
{
    return *getObjectIter(id);
}

Iterator Scene::begin()
{
    return _objects->begin();
}

Iterator Scene::end()
{
    return _objects->end();
}
