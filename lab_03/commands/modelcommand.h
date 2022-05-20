#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include "basecommand.h"
#include "object.h"
#include "loadmanager.h"
#include "scenemanager.h"
#include "transformmanager.h"
#include "modelloadmoderator.h"

using ID = std::shared_ptr<std::size_t>;

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
public:
    MoveModel(const double dx, const double dy, const double dz, const std::size_t id,
              const std::shared_ptr<SceneManager> sceneManager,
              const std::shared_ptr<TransformManager> transformManager);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};


class ScaleModel : public ModelCommand
{
public:
    ScaleModel(const double kx, const double ky, const double kz, const std::size_t id,
               const std::shared_ptr<SceneManager> sceneManager,
               const std::shared_ptr<TransformManager> transformManager);

    virtual void execute() override;

private:
    double _kx, _ky, _kz;
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};


class RotateModel : public ModelCommand
{
public:
    RotateModel(const double ox, const double oy, const double oz, const std::size_t id,
                const std::shared_ptr<SceneManager> sceneManager,
                const std::shared_ptr<TransformManager> transformManager);

    virtual void execute() override;

private:
    double _ox, _oy, _oz;
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};

class TransformModel : public ModelCommand
{
public:
    TransformModel(const Matrix<double> &mtr, const std::size_t id,
                   const std::shared_ptr<SceneManager> sceneManager,
                   const std::shared_ptr<TransformManager> transformManager);

    virtual void execute() override;

private:
    Matrix<double> _mtr;
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<TransformManager> _transformManager;
};


class DeleteModel : public ModelCommand
{
public:
    DeleteModel(const std::size_t id,
                const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    std::size_t _id;
    std::shared_ptr<SceneManager> _sceneManager;
};


class LoadModel : public ModelCommand
{
public:
    LoadModel(const ID &id, std::string &fileName,
              const std::shared_ptr<ModelLoadModerator> modelLoadModerator,
              const std::shared_ptr<LoadManager> loadManager,
              const std::shared_ptr<SceneManager> sceneManager);

    virtual void execute() override;

private:
    std::string _fileName;
    ID _id;
    std::shared_ptr<ModelLoadModerator> _modelLoadModerator;
    std::shared_ptr<LoadManager> _loadManager;
    std::shared_ptr<SceneManager> _sceneManager;
};

#endif //MODELCOMMAND_H
