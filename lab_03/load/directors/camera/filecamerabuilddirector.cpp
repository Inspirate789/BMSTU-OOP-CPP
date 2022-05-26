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

std::shared_ptr<Camera> FileCameraBuildDirector::load(std::shared_ptr<BaseCameraBuilder> builder,
                                                      std::string &fileName)
{
    _reader->open(fileName);

    builder->build();
    Vertex location = _reader->readVertex();
    builder->buildLocation(location);

    _reader->close();

    return builder->get();
}
