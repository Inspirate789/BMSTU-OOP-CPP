#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H


#include "modelstructure.h"
#include "carcassmodel.h"
#include "basebuilder.h"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual void buildVertex(const Vertex &vertex) = 0;
    virtual void buildLink(const Link &link) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

protected:
    std::shared_ptr<ModelStructure> _model;
};

#endif // BASEMODELBUILDER_H
