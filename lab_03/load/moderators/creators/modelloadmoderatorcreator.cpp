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
        auto reader = std::shared_ptr<FileCarcassModelReader>(new FileCarcassModelReader());
        auto director = std::shared_ptr<BaseModelBuildDirector>(new FileModelBuildDirector(reader));
        moderator = std::make_shared<ModelLoadModerator>(director);
    }

    _moderator = moderator;
}
