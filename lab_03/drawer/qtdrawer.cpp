#include "qtdrawer.h"

QtDrawer::QtDrawer(QGraphicsScene *scene)
{
    _scene = scene;
}


QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    _scene = drawer._scene;
}


void QtDrawer::drawLine(const Vertex &vertex1, const Vertex &vertex2)
{
    _scene->addLine(vertex1.getX(), vertex1.getY(), vertex2.getX(), vertex2.getY());
}


void QtDrawer::clearScene()
{
    _scene->clear();
}
