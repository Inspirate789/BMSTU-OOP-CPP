#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>

#include "basedirector.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &fileName) = 0;
    virtual void setLoader(std::shared_ptr<BaseDirector> director);

protected:
    std::shared_ptr<BaseDirector> _director;
};

#endif // BASELOADMODERATOR_H
