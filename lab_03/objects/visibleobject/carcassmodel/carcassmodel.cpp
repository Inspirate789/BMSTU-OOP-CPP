#include "carcassmodel.h"

CarcassModel::CarcassModel(const CarcassModel &model)
{
    _modelStructure = model._modelStructure;
    _id = model._id;
}

Vertex CarcassModel::getCenter() const
{
    return _modelStructure->getCenter();
}

void CarcassModel::transform(const Matrix<double> &mtr)
{
    _modelStructure->transform(mtr);
}
