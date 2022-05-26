#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include <memory>
#include <utility>

#include "object.h"
#include "basemodel.h"
#include "vertex.h"
#include "link.h"
#include "modelstructure.h"
#include "drawcarcassmodeladapter.h"

class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel() : _modelStructure(new ModelStructure) { }
    explicit CarcassModel(const std::shared_ptr<ModelStructure> &modelStructure) :
        _modelStructure(modelStructure) { }
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void transform(const Matrix<double> &mtr, const Vertex &center) override;

protected:
    std::shared_ptr<ModelStructure> _modelStructure;
};


#endif // CARCASSMODEL_H
