#include "carcassmodel.h"

CarcassModel::CarcassModel(const CarcassModel &model)
{
    _modelStructure = model._modelStructure;
    _id = model._id;
}

void CarcassModel::transform(const Vertex &move, const Vertex &scale, const Vertex &rotate)
{
    _modelStructure->transform(move, scale, rotate);
}

void CarcassModel::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
