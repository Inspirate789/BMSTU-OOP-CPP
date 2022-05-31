#include <QDebug>

#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _status = STANDING;

    QObject::connect(this, SIGNAL(_movingSignal()),
                     this, SLOT(_moveSlot()));
    QObject::connect(&_moveTimer, SIGNAL(timeout()),
                     this, SLOT(_moveSlot()));
    QObject::connect(this, SIGNAL(_openDoorsSignal()),
                     &_door, SLOT(openingSlot()));
    QObject::connect(&_door, SIGNAL(_closedSignal()),
                     this, SLOT(_continueMovingSlot()));
}

void Cabin::_moveSlot()
{
    _status = MOVING;

    emit _floorPassedSignal(_currentFloor, _direction);

    if (_currentFloor != _neededFloor)
    {
        _moveTimer.start(MOVING_TIME);
        qDebug() << "Лифт на" << _currentFloor << "этаже";

        _direction = _currentFloor > _neededFloor ? DOWN : UP;
        _currentFloor += _direction;
    }
}

void Cabin::startMovingSlot(ssize_t &neededFloor, ssize_t &currentFloor, Direction &direction)
{
    if (_status == STANDING)
    {
        _saveState(neededFloor, currentFloor, direction);
        emit _movingSignal();
        _restoreState(neededFloor, currentFloor, direction);
    }
}

void Cabin::_continueMovingSlot()
{
    if (_status == STANDING && _currentFloor != _neededFloor)
        emit _movingSignal();
}

void Cabin::stoppedSlot(bool isLast, ssize_t currentFloor, ssize_t neededFloor)
{
    _status = STANDING;

    if (!isLast)
    {
        _currentFloor = currentFloor;
        _neededFloor = neededFloor;
    }

    _moveTimer.stop();
    emit _openDoorsSignal();
}

void Cabin::_saveState(const ssize_t &neededFloor, const ssize_t &currentFloor, const Direction &direction)
{
    _neededFloor = neededFloor;
    _currentFloor = currentFloor;
    _direction = direction;
}

void Cabin::_restoreState(ssize_t &neededFloor, ssize_t &currentFloor, Direction &direction)
{
    neededFloor = _neededFloor;
    currentFloor = _currentFloor;
    direction = _direction;
}
