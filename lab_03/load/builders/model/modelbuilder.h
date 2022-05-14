#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "basemodelbuilder.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    void build() override;
    void buildVertex(const double x, const double y, const double z) override;
    void buildLink(const std::size_t vertex1Index, const std::size_t vertex2Index) override;
    bool isBuild() const override;

    std::shared_ptr<CarcassModel> get() override;
};

#endif //BUILDER_MODEL_H
