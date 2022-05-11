#include <QDebug>

#include "modelloadmoderator.h"
#include "exceptions.h"
#include "modelbuilder.h"


ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director) : _builder(new ModelBuilder)
{
    _director = director;
}


std::shared_ptr<Object> ModelLoadModerator::load(std::string &file_name)
{
    try
    {
        _director->open(file_name);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }

    std::shared_ptr<CarcassModel> model_ptr;

    try
    {
        model_ptr = _director->load(_builder);
    }
    catch (std::exception &error)
    {
        _director->close();
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _director->close();

    return std::make_shared<Object>(*model_ptr);
}
