#ifndef FILECARCASSMODELREADER_H
#define FILECARCASSMODELREADER_H

#include <fstream>

#include "basecarcassmodelreader.h"


class FileCarcassModelReader : public BaseCarcassModelReader
{
public:
    FileCarcassModelReader();
    FileCarcassModelReader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t readCount() override;
    virtual Vertex readVertex() override;
    virtual std::vector<Vertex> readVertexes() override;
    virtual std::vector<Link> readLinks(int &vertexNum) override;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILECARCASSMODELREADER_H
