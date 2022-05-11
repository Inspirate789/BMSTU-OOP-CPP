#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "vertex.h"
#include "composite.h"
#include "object.h"
#include "scene.h"
#include "basedrawer.h"
#include "baseadapter.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    void setAdapter(std::shared_ptr<CompositeAdapter> adapter);

    void drawScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<CompositeAdapter> _adapter;
};

#endif //DRAWMANAGER_H
