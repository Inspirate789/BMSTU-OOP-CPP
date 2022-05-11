#ifndef BASESCENEBUILDDIRECTOR_H
#define BASESCENEBUILDDIRECTOR_H


#include "scenebuilder.h"

class BaseSceneBuildDirector
{
public:
    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder) = 0;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder) = 0;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder) = 0;
};

#endif // BASESCENEBUILDDIRECTOR_H
