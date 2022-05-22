#ifndef SCENE_H
#define SCENE_H

#include "composite.h"
#include "camera.h"
#include "vertex.h"

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Scene
{
    friend class DrawManager;

public:
    Scene();
    ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);
    std::size_t addCamera(const Vertex &location);
    void deleteObject(Iterator &iter);
    Iterator getObjectIter(const std::size_t id);
    std::shared_ptr<Object> getObject(const std::size_t id);

    Iterator begin();
    Iterator end();

protected:
    std::shared_ptr<Composite> _objects;
};

#endif //SCENE_H
