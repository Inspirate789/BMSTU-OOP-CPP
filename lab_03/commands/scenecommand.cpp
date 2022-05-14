#include "scenecommand.h"
#include "solution.h"
#include "crcreator.h"
#include "scenemanager.h"
#include "drawmanager.h"
#include "loadmanager.h"
#include "basedrawer.h"
#include "drawcompositeadapter.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    shared_ptr<Solution<DrawManager>> solution_draw(new Solution<DrawManager>({ {1, &CrCreator<DrawManager>::createProdCreator} }));
    solution_draw->registration(2, &CrCreator<DrawManager>::createProdCreator);
    auto drawManager = solution_draw->create(2);

    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);
    auto sceneManager = solution_scene->create(2);

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
    shared_ptr<Solution<SceneLoadModerator>> solution_mod(new Solution<SceneLoadModerator>({ {1, &CrCreator<SceneLoadModerator>::createProdCreator} }));
    solution_mod->registration(2, &CrCreator<SceneLoadModerator>::createProdCreator);
    auto moderator = solution_mod->create(2);

    shared_ptr<Solution<LoadManager>> solution(new Solution<LoadManager>({ {1, &CrCreator<LoadManager>::createProdCreator} }));
    solution->registration(2, &CrCreator<LoadManager>::createProdCreator);
    auto manager = solution->create(2);

    manager->setSceneLoader(moderator);
    auto scene = manager->loadScene(_fileName);

    shared_ptr<Solution<SceneManager>> solution_scene(new Solution<SceneManager>({ {1, &CrCreator<SceneManager>::createProdCreator} }));
    solution_scene->registration(2, &CrCreator<SceneManager>::createProdCreator);

    solution_scene->create(2)->setScene(scene);
}
