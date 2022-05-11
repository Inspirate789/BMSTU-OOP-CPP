#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

#include "basemanager.h"
#include "basemodel.h"
#include "baseloadmoderator.h"
#include "sceneloadmoderator.h"
#include "modelloadmoderator.h"

class LoadManager : BaseManager
{
public:
    LoadManager() = default;
    LoadManager(const LoadManager &manager) = delete;
    LoadManager &operator = (const LoadManager &manager) = delete;

    ~LoadManager() = default;

    std::shared_ptr<Object> load(std::string &name);
    std::shared_ptr<Scene> loadScene(std::string &name);
    void setLoader(std::shared_ptr<BaseLoadModerator> loader);
    void setSceneLoader(std::shared_ptr<SceneLoadModerator> loader);

private:
    std::shared_ptr<ModelLoadModerator> _loader;
    std::shared_ptr<SceneLoadModerator> _sceneLoader;
};

#endif // LOADMANAGER_H
