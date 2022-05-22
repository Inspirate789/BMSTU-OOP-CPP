#include "scenecommand.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }

void DrawScene::execute()
{
    _drawCompositeAdapter->setDrawer(_drawer);
    _drawer->clearScene();
    _drawManager->drawScene(_scene);
}



LoadScene::LoadScene(const std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    auto scene = _loadManager->loadScene(_fileName);
    _sceneManager->setScene(scene);
}
