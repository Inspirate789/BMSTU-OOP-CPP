#ifndef SCENELOADMODERATOR_H
#define SCENELOADMODERATOR_H

#include "basescenebuilddirector.h"
#include "scenebuilder.h"

class SceneLoadModerator
{
public:
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneBuildDirector> loader);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Scene> load(std::string &fileName);
    virtual void setDirector(std::shared_ptr<BaseSceneBuildDirector> director);

private:
    std::shared_ptr<SceneBuilder> _builder;
    std::shared_ptr<BaseSceneBuildDirector> _director;
};

#endif //SCENELOADMODERATOR_H
