#ifndef MODELLOADMODERATOR_H
#define MODELLOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basemodelbuilddirector.h"
#include "basemodelbuilder.h"

class ModelLoadModerator : public BaseLoadModerator
{
public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> loader);

    ~ModelLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<BaseModelBuilder> _builder;
    std::shared_ptr<BaseModelBuildDirector> _director;
};

#endif // MODELLOADMODERATOR_H
