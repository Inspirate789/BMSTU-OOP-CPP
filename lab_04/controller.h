#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define FLOOR_COUNT 9
#define DOORS_TIME  600
#define MOVING_TIME 3200

enum Direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1
};

class Controller : public QWidget
{
    Q_OBJECT;

    enum ControllerStatus
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() = default;

public slots:
    void newTargetSlot(ssize_t floor);
    void floorPassedSlot(ssize_t floor, Direction direction);
    void controllerStoppedSlot();

private:
    bool _targetExist(ssize_t &newFloor);

    ControllerStatus _status;
    Direction _direction;
    ssize_t _currentFloor;
    ssize_t _neededFloor;

    std::vector<std::shared_ptr<Button>> _buttons;
    std::vector<bool> _visitedFloors;
    std::unique_ptr<QVBoxLayout> _layout;

signals:
    void _controllerStoppedSignal();
    void _cabinStoppedSignal(bool, ssize_t, ssize_t = 1);
    void _startMovingSignal(ssize_t &neededFloor, ssize_t &_currentFloor, Direction &Direction);
    void _floorPassedSignal(ssize_t floor, Direction direction);
};

#endif
