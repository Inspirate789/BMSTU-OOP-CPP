#ifndef FILESCENEBUILDDIRECTOR_H
#define FILESCENEBUILDDIRECTOR_H


#include "basescenebuilddirector.h"
#include "filecarcassmodelreader.h"

class FileSceneBuildDirector : public BaseSceneBuildDirector
{
public:
    FileSceneBuildDirector();
    explicit FileSceneBuildDirector(std::shared_ptr<FileCarcassModelReader> &reader);
    ~FileSceneBuildDirector() = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder) override;

protected:
    void loadModels(std::shared_ptr<SceneBuilder> builder) override;
    void loadCameras(std::shared_ptr<SceneBuilder> builder) override;

    std::shared_ptr<FileCarcassModelReader> _reader;
};

#endif // FILESCENEBUILDDIRECTOR_H
