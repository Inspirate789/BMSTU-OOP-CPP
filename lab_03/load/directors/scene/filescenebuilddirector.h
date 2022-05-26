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

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder,
                                std::string &fileName) override;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder,
                    std::string &fileName) override;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder,
                     std::string &fileName) override;

    std::shared_ptr<FileCarcassModelReader> _reader;
};

#endif // FILESCENEBUILDDIRECTOR_H
