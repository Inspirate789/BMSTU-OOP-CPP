#include "scenecommand.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer,
                     const std::shared_ptr<DrawManager> drawManager,
                     const std::shared_ptr<SceneManager> sceneManager,
                     const std::shared_ptr<DrawCompositeAdapter> drawCompositeAdapter) :
    _drawer(drawer),
    _drawManager(drawManager), _sceneManager(sceneManager),
    _drawCompositeAdapter(drawCompositeAdapter) { }


void DrawScene::execute()
{
    auto camera = _sceneManager->getCamera();
    _drawCompositeAdapter->setCamera(camera);
    _drawCompositeAdapter->setDrawer(_drawer);

    _drawer->clearScene();
    _drawManager->setAdapter(_drawCompositeAdapter);
    _drawManager->drawScene(_sceneManager->getScene());
}


LoadScene::LoadScene(const std::string fileName,
                     const std::shared_ptr<LoadManager> loadManager,
                     const std::shared_ptr<SceneLoadModerator> sceneLoadModerator,
                     const std::shared_ptr<SceneManager> sceneManager) :
    _fileName(fileName),
    _loadManager(loadManager), _sceneLoadModerator(sceneLoadModerator),
    _sceneManager(sceneManager) { }

void LoadScene::execute()
{
    _loadManager->setSceneModerator(_sceneLoadModerator);
    auto scene = _loadManager->loadScene(_fileName);

    _sceneManager->setScene(scene);
}
