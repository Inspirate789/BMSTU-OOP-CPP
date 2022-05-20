#include "filemodelbuilddirector.h"
#include "exceptions.h"
#include "modelbuilder.h"


FileModelBuildDirector::FileModelBuildDirector()
{
    _reader = std::make_shared<FileCarcassModelReader>();
}


FileModelBuildDirector::FileModelBuildDirector(std::shared_ptr<FileCarcassModelReader> &reader)
{
    _reader = reader;
}


void FileModelBuildDirector::open(std::string &fileName)
{
    _reader->open(fileName);
}


void FileModelBuildDirector::close()
{
    _reader->close();
}


std::shared_ptr<CarcassModel> FileModelBuildDirector::load(std::shared_ptr<BaseModelBuilder> builder)
{
    builder->build();

    vector<Vertex> vertexes = _reader->readVertexes();
    int vertexNum = vertexes.size();

    std::vector<Link> links = _reader->readLinks(vertexNum);
    int linksNum = links.size();

    for (int i = 0; i < vertexNum; i++)
        builder->buildVertex(vertexes[i]);

    for (int i = 0; i < linksNum; i++)
        builder->buildLink(links[i]);

    std::shared_ptr<CarcassModel> model = builder->get();

    return model;
}
