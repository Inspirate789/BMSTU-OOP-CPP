#ifndef FILEMODELBUILDDIRECTOR_H
#define FILEMODELBUILDDIRECTOR_H


#include "basemodelbuilddirector.h"

class FileModelBuildDirector : public BaseModelBuildDirector
{
public:
    FileModelBuildDirector();
    explicit FileModelBuildDirector(std::shared_ptr<std::ifstream> &file);

    ~FileModelBuildDirector() override = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILEMODELBUILDDIRECTOR_H
