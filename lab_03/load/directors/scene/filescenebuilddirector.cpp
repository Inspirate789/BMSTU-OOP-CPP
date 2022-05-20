#include "filescenebuilddirector.h"
#include "filecamerabuilddirector.h"
#include "filemodelbuilddirector.h"
#include "exceptions.h"

FileSceneBuildDirector::FileSceneBuildDirector()
{
    _reader = std::make_shared<FileCarcassModelReader>();
}

FileSceneBuildDirector::FileSceneBuildDirector(std::shared_ptr<FileCarcassModelReader> &reader)
{
    _reader = reader;
}


void FileSceneBuildDirector::open(std::string &fileName)
{
    _reader->open(fileName);
}


void FileSceneBuildDirector::close()
{
    _reader->close();
}


std::shared_ptr<Scene> FileSceneBuildDirector::load(std::shared_ptr<SceneBuilder> builder)
{
    builder->build();

    loadModels(builder);
    loadCameras(builder);

    return builder->get();
}

void FileSceneBuildDirector::loadModels(std::shared_ptr<SceneBuilder> builder)
{
    size_t modelsCount = _reader->readCount();

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < modelsCount; i++)
    {
        std::shared_ptr<CarcassModel> model_sh_ptr = FileModelBuildDirector(_reader).load(modBuilder);
        builder->buildObject(model_sh_ptr);
    }
}

void FileSceneBuildDirector::loadCameras(std::shared_ptr<SceneBuilder> builder)
{
    size_t camsCount = _reader->readCount();

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < camsCount; i++)
    {
        std::shared_ptr<Camera> cam_sh_ptr = FileCameraBuildDirector(_reader).load(camBuilder);
        builder->buildObject(cam_sh_ptr);
    }
}
