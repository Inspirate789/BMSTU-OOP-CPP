#ifndef SCENE_H
#define SCENE_H

#include "composite.h"

class Scene
{
public:
    Scene();
    ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);
    void deleteObject(Iterator &iter);
    Iterator getObject(const std::size_t id);

    Iterator begin();
    Iterator end();

protected:
    std::shared_ptr<Composite> _objects;
};

#endif //SCENE_H
