#ifndef FILECAMERABUILDDIRECTOR_H
#define FILECAMERABUILDDIRECTOR_H


#include "basecamerabuilddirector.h"

class FileCameraBuildDirector : public BaseCameraBuildDirector
{
public:
    FileCameraBuildDirector();
    explicit FileCameraBuildDirector(std::shared_ptr<std::ifstream> &file);

    ~FileCameraBuildDirector() override = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Camera> load(std::shared_ptr<BaseCameraBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILECAMERABUILDDIRECTOR_H
