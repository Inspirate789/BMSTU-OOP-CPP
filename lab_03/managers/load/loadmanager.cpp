#include "loadmanager.h"

#include <QDebug>

std::shared_ptr<Object> LoadManager::load(std::string &name)
{
    return _loader->load(name);
}

std::shared_ptr<Scene> LoadManager::loadScene(std::string &name)
{
    return _sceneLoader->load(name);
}

void LoadManager::setLoader(std::shared_ptr<BaseLoadModerator> loader)
{
    _loader = loader;
}

void LoadManager::setSceneLoader(std::shared_ptr<SceneLoadModerator> loader)
{
    _sceneLoader = loader;
}
