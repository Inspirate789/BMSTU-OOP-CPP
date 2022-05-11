#ifndef DRAWERFACTORYDIRECTOR_H
#define DRAWERFACTORYDIRECTOR_H

#include "abstractdrawerfactory.h"
#include "qtdrawerfactory.h"

class DrawerFactoryDirector
{
public:
    std::unique_ptr<BaseDrawer> createDrawer(QGraphicsScene *scene);
};

#endif // DRAWERFACTORYDIRECTOR_H
