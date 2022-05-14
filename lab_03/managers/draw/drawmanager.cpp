#include "drawmanager.h"
#include "basemodel.h"
#include "camera.h"

void DrawManager::setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter)
{
    _adapter = adapter;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene)
{
    for (auto &elem : *scene)
    {
        Object *object_ptr = elem.get();
        Composite *com_ptr = dynamic_cast<Composite *>(object_ptr);
        std::shared_ptr<Composite> com_sh_ptr = std::make_shared<Composite>(*com_ptr);
        _adapter->setAdaptee(com_sh_ptr);
        _adapter->request();
    }
}
