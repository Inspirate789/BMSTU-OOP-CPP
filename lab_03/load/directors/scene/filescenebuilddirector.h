#ifndef FILESCENEBUILDDIRECTOR_H
#define FILESCENEBUILDDIRECTOR_H


#include "basescenebuilddirector.h"

class FileSceneBuildDirector : public BaseSceneBuildDirector
{
public:
    FileSceneBuildDirector();
    explicit FileSceneBuildDirector(std::shared_ptr<std::ifstream> &fileIn);
    ~FileSceneBuildDirector() = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder) override;

protected:
    void loadModels(std::shared_ptr<SceneBuilder> builder) override;
    void loadCameras(std::shared_ptr<SceneBuilder> builder) override;

    std::shared_ptr<std::ifstream> _file;
};

#endif // FILESCENEBUILDDIRECTOR_H
