#include "carcassmodel.h"

CarcassModel::CarcassModel(const CarcassModel &model)
{
    _modelStructure = model._modelStructure;
    _id = model._id;
}

void CarcassModel::transform(const Matrix<double> &mtr)
{
    _modelStructure->transform(mtr);
}
