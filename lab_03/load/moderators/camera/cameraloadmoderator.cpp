#include "cameraloadmoderator.h"
#include "exceptions.h"
#include "camerabuilder.h"


CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraBuildDirector> director) :
    _builder(new CameraBuilder)
{
    _director = director;
}

std::shared_ptr<Object> CameraLoadModerator::load(std::string &fileName)
{
    try
    {
        _director->open(fileName);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }

    std::shared_ptr<Camera> camera_ptr;

    try
    {
        camera_ptr = _director->load(_builder);
    }
    catch (std::exception &error)
    {
        _director->close();
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _director->close();

    return std::make_shared<Object>(*camera_ptr);
}
