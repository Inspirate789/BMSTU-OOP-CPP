#include "drawcompositeadapter.h"

void DrawCompositeAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCompositeAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

class CarcassModel;
class Object;
class BaseModel;

void DrawCompositeAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        for (auto &elem : _adaptee->_elements)
        {
            if (elem->isComposite())
            {
                auto adapter = std::make_shared<DrawCompositeAdapter>(DrawCompositeAdapter());
                adapter->setAdaptee(std::make_shared<Composite>(*elem));
                adapter->setCamera(_camera);
                adapter->setDrawer(_drawer);
                adapter->request();
            }
            else
            {
                std::shared_ptr<DrawCarcassModelAdapter> adapter = std::make_shared<DrawCarcassModelAdapter>(DrawCarcassModelAdapter());
                Object *object_ptr = elem.get();
                CarcassModel *model_ptr = dynamic_cast<CarcassModel *>(object_ptr);
                std::shared_ptr<CarcassModel> model_sh_ptr = std::make_shared<CarcassModel>(model_ptr);
                adapter->setAdaptee(model_sh_ptr); // WHY?!
                adapter->setCamera(_camera);
                adapter->setDrawer(_drawer);
                adapter->request();
            }
        }
    }
}
