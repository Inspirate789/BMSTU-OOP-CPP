#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "object.h"

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() override { return true; }
};

#endif //VISIBLEOBJECT_H
