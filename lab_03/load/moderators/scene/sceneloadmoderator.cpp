#include "sceneloadmoderator.h"
#include "exceptions.h"


SceneLoadModerator::SceneLoadModerator(std::shared_ptr<BaseSceneBuildDirector> director) :
    _builder(new SceneBuilder)
{
    _director = director;
}

std::shared_ptr<Scene> SceneLoadModerator::load(std::string &fileName)
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

    std::shared_ptr<Scene> scene;

    try
    {
        scene = _director->load(_builder);
    }
    catch (std::exception &error)
    {
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _director->close();

    return scene;
}

void SceneLoadModerator::setDirector(std::shared_ptr<BaseSceneBuildDirector> director)
{
    _director = director;
}
