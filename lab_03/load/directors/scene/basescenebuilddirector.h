#ifndef BASESCENEBUILDDIRECTOR_H
#define BASESCENEBUILDDIRECTOR_H


#include "scenebuilder.h"

class BaseSceneBuildDirector
{
public:
    virtual std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName) = 0;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder,
                            std::string &fileName) = 0;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder,
                             std::string &fileName) = 0;
};

#endif // BASESCENEBUILDDIRECTOR_H
