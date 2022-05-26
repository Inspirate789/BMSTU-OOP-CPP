#ifndef BASECAMERABUILDDIRECTOR_H
#define BASECAMERABUILDDIRECTOR_H


#include "basedirector.h"
#include "camerabuilder.h"

class BaseCameraBuildDirector : public BaseDirector
{
public:
    virtual std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder,
                                         std::string &fileName) = 0;
};

#endif // BASECAMERABUILDDIRECTOR_H
