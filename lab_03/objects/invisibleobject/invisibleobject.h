#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool isVisible() override { return false; }
};

#endif //INVISIBLEOBJECT_H
