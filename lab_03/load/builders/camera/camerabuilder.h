#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basecamerabuilder.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void build() override;
    void buildLocation(const double x, const double y, const double z) override;
    bool isBuild() const override;

    std::shared_ptr<Camera> get() override;
};

#endif //CAMERABUILDER_H
