#include "sceneloadmoderatorcreator.h"
#include "filescenebuilddirector.h"

std::shared_ptr<SceneLoadModerator> SceneLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void SceneLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<SceneLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseSceneBuildDirector> director;
        director = std::shared_ptr<BaseSceneBuildDirector>(new FileSceneBuildDirector);
        moderator = std::make_shared<SceneLoadModerator>(director);
    }

    _moderator = moderator;
}


