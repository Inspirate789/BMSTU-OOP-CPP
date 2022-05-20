#ifndef CAMERALOADMODERATOR_H
#define CAMERALOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basecamerabuilddirector.h"

class CameraLoadModerator : public BaseLoadModerator
{
public:
    explicit CameraLoadModerator(std::shared_ptr<BaseCameraBuildDirector> director);
    ~CameraLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<BaseCameraBuilder> _builder;
    std::shared_ptr<BaseCameraBuildDirector> _director;
};

#endif // CAMERALOADMODERATOR_H
