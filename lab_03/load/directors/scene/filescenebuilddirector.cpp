#include "filescenebuilddirector.h"
#include "filecamerabuilddirector.h"
#include "filemodelbuilddirector.h"
#include "exceptions.h"

FileSceneBuildDirector::FileSceneBuildDirector()
{
    _file = std::make_shared<std::ifstream>();
}

FileSceneBuildDirector::FileSceneBuildDirector(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}


void FileSceneBuildDirector::open(std::string &file_name)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(file_name);

    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}


void FileSceneBuildDirector::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
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
    int num;

    *_file >> num;

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (int i = 0; i < num; i++)
    {
        auto model = std::make_shared<Object>(*(FileModelBuildDirector(_file).load(modBuilder)));
        builder->buildObject(model);
    }
}

void FileSceneBuildDirector::loadCameras(std::shared_ptr<SceneBuilder> builder)
{
    int num;

    *_file >> num;

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (int i = 0; i < num; i++)
    {
        auto cam = std::make_shared<Object>(*(FileCameraBuildDirector(_file).load(camBuilder)));
        builder->buildObject(cam);
    }
}
