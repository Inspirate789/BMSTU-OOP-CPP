#include "filecamerabuilddirector.h"
#include "exceptions.h"

FileCameraBuildDirector::FileCameraBuildDirector()
{
    _file = std::make_shared<std::ifstream>();
}

FileCameraBuildDirector::FileCameraBuildDirector(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void FileCameraBuildDirector::open(std::string &fileName)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(fileName);

    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}

void FileCameraBuildDirector::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::shared_ptr<Camera> FileCameraBuildDirector::load(std::shared_ptr<BaseCameraBuilder> builder)
{
    builder->build();

    double x, y, z;

    *_file >> x >> y >> z;

    builder->buildLocation(x, y, z);

    return builder->get();
}
