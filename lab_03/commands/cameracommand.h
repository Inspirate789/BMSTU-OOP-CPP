#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <memory>
#include <cstddef>

#include "basecommand.h"
#include "camera.h"
#include "scenemanager.h"
#include "transformmanager.h"

using ID = std::shared_ptr<std::size_t>;

class CameraCommand : public BaseCommand {};

class AddCamera: public CameraCommand
{
public:
    AddCamera(const ID & id,
              const std::shared_ptr<Camera> camera,
              const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    ID _id;
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<SceneManager> _sceneManager;
};


class DeleteCamera: public CameraCommand
{
public:
    DeleteCamera(const std::size_t id,
                 const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
};


class MoveCamera: public CameraCommand
{
public:
    MoveCamera(const double dx, const double dy, const double dz,
               const size_t id,
               const std::shared_ptr<SceneManager> sceneManager,
               const std::shared_ptr<TransformManager> transformManager);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};


class SetCamera: public CameraCommand
{
public:
    explicit SetCamera(const std::size_t id,
                       const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
};

#endif //CAMERACOMMAND_H
