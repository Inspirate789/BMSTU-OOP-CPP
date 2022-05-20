#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>

#include "object.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &fileName) = 0;
};

#endif // BASELOADMODERATOR_H
