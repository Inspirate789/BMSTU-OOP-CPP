#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include <string>

#include "basecommand.h"
#include "basedrawer.h"
#include "drawmanager.h"
#include "loadmanager.h"
#include "scenemanager.h"
#include "cameraloadmoderator.h"
#include "sceneloadmoderator.h"
#include "drawcompositeadapter.h"

class SceneCommand : public BaseCommand { };

class DrawScene : public SceneCommand
{
public:
    DrawScene(std::shared_ptr<BaseDrawer> drawer,
              const std::shared_ptr<DrawManager> drawManager,
              const std::shared_ptr<SceneManager> sceneManager,
              const std::shared_ptr<DrawCompositeAdapter> drawCompositeAdapter);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<DrawManager> _drawManager;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<DrawCompositeAdapter> _drawCompositeAdapter;
};


class LoadScene : public SceneCommand
{
public:
    LoadScene(const std::string fileName,
              const std::shared_ptr<LoadManager> loadManager,
              const std::shared_ptr<SceneLoadModerator> sceneLoadModerator,
              const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    std::string _fileName;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneLoadModerator> _sceneLoadModerator;
    std::shared_ptr<SceneManager> _sceneManager;
};

#endif //SCENECOMMAND_H
