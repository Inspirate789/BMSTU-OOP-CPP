#ifndef BASECARCASSMODELREADER_H
#define BASECARCASSMODELREADER_H

#include <string>
#include <vector>

#include "vertex.h"
#include "link.h"


class BaseCarcassModelReader
{
public:
    BaseCarcassModelReader() = default;
    virtual ~BaseCarcassModelReader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t readCount() = 0;
    virtual Vertex readVertex() = 0;
    virtual std::vector<Vertex> readVertexes() = 0;
    virtual std::vector<Link> readLinks(int &vertexNum) = 0;
};

#endif // BASECARCASSMODELREADER_H
