#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "basescenebuilder.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void buildObject(const std::shared_ptr<Object> &object) override;
    bool isBuild() const override;

    std::shared_ptr<Scene> get() override;

private:
    std::shared_ptr<Scene> _scene;
};


#endif //SCENEBUILDER_H
