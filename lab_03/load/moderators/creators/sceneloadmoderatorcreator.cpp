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
        std::shared_ptr<BaseSceneBuildDirector> loader;
        loader = std::shared_ptr<BaseSceneBuildDirector>(new FileSceneBuildDirector);
        moderator = std::make_shared<SceneLoadModerator>(loader);
    }

    _moderator = moderator;
}


