#include "baseloadmoderator.h"

void BaseLoadModerator::setLoader(std::shared_ptr<BaseDirector> director)
{
    _director = director;
}
