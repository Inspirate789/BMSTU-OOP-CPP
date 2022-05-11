#include "drawerfactorydirector.h"

std::unique_ptr<BaseDrawer> DrawerFactoryDirector::createDrawer(QGraphicsScene *scene)
{
    std::shared_ptr<AbstractDrawerFactory> factory(new QtDrawerFactory(scene));

    return factory->createDrawer();
}
