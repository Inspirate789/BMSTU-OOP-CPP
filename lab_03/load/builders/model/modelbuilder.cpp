#include "modelbuilder.h"

void ModelBuilder::build()
{
    _model = std::make_shared<ModelStructure>();
}


void ModelBuilder::buildVertex(const double x, const double y, const double z)
{
    if (!isBuild()) {}

    Vertex tmp(x, y, z);
    _model->addVertex(tmp);
}


void ModelBuilder::buildLink(const std::size_t vertex1Index, const std::size_t vertex2Index)
{
    if (!isBuild()) {}

    Link tmp(vertex1Index, vertex2Index);
    _model->addLink(tmp);
}


bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}
