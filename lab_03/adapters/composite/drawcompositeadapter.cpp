#include "drawcompositeadapter.h"

void DrawCompositeAdapter::setAdaptee(std::shared_ptr<Composite> adaptee)
{
    _adaptee = adaptee;
}

void DrawCompositeAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCompositeAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

void DrawCompositeAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        for (auto &elem : _adaptee->_elements)
        {
            if (elem->isComposite())
            {
                auto adapter = std::make_shared<DrawCompositeAdapter>(elem);
                adapter->request();
            }
            else
            {
                auto adapter = std::make_shared<DrawCarcassModelAdapter>(elem);
                adapter->request();
            }
        }
    }
}
