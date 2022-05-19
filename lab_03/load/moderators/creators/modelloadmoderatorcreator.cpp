#include "modelloadmoderatorcreator.h"
#include "filemodelbuilddirector.h"

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void ModelLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseModelBuildDirector> loader;
        loader = std::shared_ptr<BaseModelBuildDirector>(new FileModelBuildDirector);
        moderator = std::make_shared<ModelLoadModerator>(loader);
    }

    _moderator = moderator;
}

