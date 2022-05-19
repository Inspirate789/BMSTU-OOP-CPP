#include "scenecommand.h"
#include "managersolution.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"
#include "moderatorsolution.h"
#include "cameraloadmoderatorcreator.h"
#include "sceneloadmoderatorcreator.h"
#include "drawcompositeadapter.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    auto drawManager = ManagerSolution<DrawManagerCreator>().create();
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();

    auto camera = sceneManager->getCamera();
    auto adapter = DrawCompositeAdapter();
    adapter.setCamera(camera);
    adapter.setDrawer(_drawer);

    _drawer->clearScene();
    drawManager->setAdapter(std::make_shared<DrawCompositeAdapter>(adapter));
    drawManager->drawScene(sceneManager->getScene());
}


LoadScene::LoadScene(std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    auto moderator = ModeratorSolution<SceneLoadModeratorCreator>().create();
    auto manager = ManagerSolution<LoadManagerCreator>().create();

    manager->setSceneLoader(moderator);
    auto scene = manager->loadScene(_fileName);

    ManagerSolution<SceneManagerCreator>().create()->setScene(scene);
}
