#include "cameraloadmoderatorcreator.h"
#include "filecamerabuilddirector.h"

std::shared_ptr<CameraLoadModerator> CameraLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void CameraLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<CameraLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseCameraBuildDirector> loader;
        loader = std::shared_ptr<BaseCameraBuildDirector>(new FileCameraBuildDirector);
        moderator = std::make_shared<CameraLoadModerator>(loader);
    }

    _moderator = moderator;
}


