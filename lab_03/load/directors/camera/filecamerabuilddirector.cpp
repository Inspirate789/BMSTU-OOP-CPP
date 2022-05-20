#include "filecamerabuilddirector.h"
#include "exceptions.h"

FileCameraBuildDirector::FileCameraBuildDirector()
{
    _reader = std::make_shared<FileCarcassModelReader>();
}

FileCameraBuildDirector::FileCameraBuildDirector(std::shared_ptr<FileCarcassModelReader> &reader)
{
    _reader = reader;
}

void FileCameraBuildDirector::open(std::string &fileName)
{
    _reader->open(fileName);
}

void FileCameraBuildDirector::close()
{
    _reader->close();
}

std::shared_ptr<Camera> FileCameraBuildDirector::load(std::shared_ptr<BaseCameraBuilder> builder)
{
    builder->build();

    Vertex location = _reader->readVertex();

    builder->buildLocation(location);

    return builder->get();
}
