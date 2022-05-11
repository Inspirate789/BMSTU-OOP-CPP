#include "drawmanager.h"
#include "basemodel.h"
#include "camera.h"

void DrawManager::setAdapter(std::shared_ptr<CompositeAdapter> adapter)
{
    _adapter = adapter;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene)
{
    for (auto &elem : *scene)
    {
        _adapter->setAdaptee(elem);
        _adapter->request();
    }
}
