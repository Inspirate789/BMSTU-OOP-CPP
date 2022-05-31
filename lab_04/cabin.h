#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "door.h"
#include "controller.h"

class Cabin : public QObject
{
    Q_OBJECT;

    enum cabin_status
    {
        STANDING,
        MOVING
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

public slots:
    void startMovingSlot(ssize_t &neededFloor, ssize_t &currentFloor, Direction &direction);
    void stoppedSlot(bool isLast, ssize_t currentFloor, ssize_t neededFloor = 1);

private:
    void _saveState(const ssize_t &neededFloor, const ssize_t &currentFloor, const Direction &direction);
    void _restoreState(ssize_t &neededFloor, ssize_t &currentFloor, Direction &direction);

    Door _door;
    ssize_t _currentFloor;
    ssize_t _neededFloor;
    Direction _direction;
    cabin_status _status;

    QTimer _moveTimer;

private slots:
    void _continueMovingSlot();
    void _moveSlot();

signals:
    void _floorPassedSignal(ssize_t floor, Direction dir);
    void _openDoorsSignal();
    void _movingSignal();
};

#endif
