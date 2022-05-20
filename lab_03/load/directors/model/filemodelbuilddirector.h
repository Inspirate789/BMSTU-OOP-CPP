#ifndef FILEMODELBUILDDIRECTOR_H
#define FILEMODELBUILDDIRECTOR_H


#include "basemodelbuilddirector.h"
#include "filecarcassmodelreader.h"

class FileModelBuildDirector : public BaseModelBuildDirector
{
public:
    FileModelBuildDirector();
    explicit FileModelBuildDirector(std::shared_ptr<FileCarcassModelReader> &reader);

    ~FileModelBuildDirector() override = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder) override;

protected:
    std::shared_ptr<FileCarcassModelReader> _reader;
};

#endif // FILEMODELBUILDDIRECTOR_H
