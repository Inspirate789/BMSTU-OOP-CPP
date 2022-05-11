#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <memory>
#include <cstddef>

#include "basecommand.h"

using ID = std::shared_ptr<std::size_t>;

class CameraCommand : public BaseCommand {};

class AddCamera: public CameraCommand
{
public:
    AddCamera(const ID &id, const double x, const double y, const double z);

    virtual void execute() override;

private:
    double _x, _y, _z;
    ID _id;
};


class DeleteCamera: public CameraCommand
{
public:
    DeleteCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
};


class MoveCamera: public CameraCommand
{
public:
    MoveCamera(const double dx, const double dy, const std::size_t id);

    virtual void execute() override;

private:
    double _dx, _dy;
    std::size_t _id;
};


class SetCamera: public CameraCommand
{
public:
    explicit SetCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t _id;
};

#endif //CAMERACOMMAND_H
