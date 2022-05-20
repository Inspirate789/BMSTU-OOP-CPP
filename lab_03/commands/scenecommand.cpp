#include "scenecommand.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    auto camera = _sceneManager->getCamera();
    _drawCompositeAdapter->setCamera(camera);
    _drawCompositeAdapter->setDrawer(_drawer);

    _drawer->clearScene();
    _drawManager->setAdapter(_drawCompositeAdapter);
    _drawManager->drawScene(_sceneManager->getScene());
}


LoadScene::LoadScene(const std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    _loadManager->setSceneModerator(_sceneLoadModerator);
    auto scene = _loadManager->loadScene(_fileName);

    _sceneManager->setScene(scene);
}
