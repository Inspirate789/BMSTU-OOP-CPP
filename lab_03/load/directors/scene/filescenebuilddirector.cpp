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

std::shared_ptr<Scene> FileSceneBuildDirector::load(std::shared_ptr<SceneBuilder> builder,
                                                    std::string &fileName)
{
    _reader->open(fileName);

    builder->build();

    loadModels(builder, fileName);
    loadCameras(builder, fileName);

    _reader->close();

    return builder->get();
}

void FileSceneBuildDirector::loadModels(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName)
{
    size_t modelsCount = _reader->readCount();

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < modelsCount; i++)
    {
        auto model = FileModelBuildDirector(_reader).load(modBuilder, fileName);
        builder->buildObject(model);
    }
}

void FileSceneBuildDirector::loadCameras(std::shared_ptr<SceneBuilder> builder,
                                         std::string &fileName)
{
    size_t camsCount = _reader->readCount();

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < camsCount; i++)
    {
        auto camera = FileCameraBuildDirector(_reader).load(camBuilder, fileName);
        builder->buildObject(camera);
    }
}
