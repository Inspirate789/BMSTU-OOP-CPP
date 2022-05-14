#include "filemodelbuilddirector.h"
#include "exceptions.h"
#include "modelbuilder.h"


FileModelBuildDirector::FileModelBuildDirector()
{
    _file = std::make_shared<std::ifstream>();
}


FileModelBuildDirector::FileModelBuildDirector(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}


void FileModelBuildDirector::open(std::string &fileName)
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


void FileModelBuildDirector::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}


std::shared_ptr<CarcassModel> FileModelBuildDirector::load(std::shared_ptr<BaseModelBuilder> builder)
{
    builder->build();

    int vertexNum;
    *_file >> vertexNum;

    if (vertexNum <= 0)
    {
        std::string msg = "wrong vertex num";
        throw SourceException(msg);
    }

    for (int i = 0; i < vertexNum; i++)
    {
        double x, y, z;

        *_file >> x >> y >> z;
        builder->buildVertex(x, y, z);
    }

    int linksNum;
    *_file >> linksNum;

    if (linksNum <= 0)
    {
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    for (int i = 0; i < linksNum; i++)
    {
        int vertex1Index, vertex2Index;

        *_file >> vertex1Index >> vertex2Index;

        if (vertex1Index <= 0 or vertex2Index <= 0 or
            vertex1Index > vertexNum or vertex2Index > vertexNum)
        {
            std::string msg = "wrong link data";
            throw SourceException(msg);
        }

        builder->buildLink(vertex1Index, vertex2Index);
    }

    return builder->get();
}
