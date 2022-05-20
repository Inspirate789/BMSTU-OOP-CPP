#include "modelbuilder.h"

void ModelBuilder::build()
{
    _model = std::make_shared<ModelStructure>();
}


void ModelBuilder::buildVertex(const Vertex &vertex)
{
    if (!isBuild()) {}

    _model->addVertex(vertex);
}


void ModelBuilder::buildLink(const Link &link)
{
    if (!isBuild()) {}

    _model->addLink(link);
}


bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}
