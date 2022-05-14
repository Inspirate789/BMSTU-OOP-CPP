#include "drawcarcassmodeladapter.h"

void DrawCarcassModelAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawCarcassModelAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

Vertex DrawCarcassModelAdapter::getProjection(const Vertex &vertex)
{
    Vertex projection = vertex;

    projection.setX(projection.getX() + _camera->_location.getX());
    projection.setY(projection.getY() + _camera->_location.getY());

    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (_adaptee && _camera && _drawer)
    {
        auto vertexes = _adaptee->_modelStructure->getVertexes();
        auto links = _adaptee->_modelStructure->getLinks();
        auto center = _adaptee->_modelStructure->getCenter();

        for (auto link : links)
        {
            _drawer->drawLine(getProjection(vertexes.at(link.getFirst() - 1)).getAbsVertex(center),
                              getProjection(vertexes.at(link.getSecond() - 1)).getAbsVertex(center));
        }
    }
}
