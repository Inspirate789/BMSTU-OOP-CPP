#include <QDebug>

#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _status = STANDING;
    _targetExist = false;

    QObject::connect(this, SIGNAL(_movingSignal()),
                     this, SLOT(_moveSlot()));
    QObject::connect(&_moveTimer, SIGNAL(timeout()),
                     this, SLOT(_moveSlot()));
    QObject::connect(this, SIGNAL(_openDoorsSignal()),
                     &_door, SLOT(openingSlot()));
    QObject::connect(&_door, SIGNAL(_closedSignal()),
                     this, SLOT(_moveSlot()));
}

void Cabin::_moveSlot()
{
    if (_targetExist)
    {
        if (_status == GET_TARGET || _status == STANDING)
            _status = MOVING;
        else
            _currentFloor += _direction;

        qDebug() << "Лифт на" << _currentFloor << "этаже";

        if (_currentFloor != _neededFloor)
            _moveTimer.start(MOVING_TIME);

        emit _floorPassedSignal(_currentFloor, _direction);
    }
}

void Cabin::getTargetSlot(ssize_t &neededFloor, ssize_t &currentFloor)
{
    if (_status == STANDING)
    {
        _status = GET_TARGET;
        _targetExist = true;
        _saveState(neededFloor, currentFloor);
        qDebug() << "Лифт на" << _currentFloor << "этаже";
        emit _movingSignal();
    }
}

void Cabin::stoppedSlot(bool isLast, ssize_t currentFloor, ssize_t neededFloor)
{
    if (_status == MOVING || _status == STANDING)
    {
        _status = STANDING;
        _saveState(neededFloor, currentFloor);
        qDebug() << "Лифт остановился на этаже: " << _currentFloor;

        if (isLast)
            _targetExist = false;

        _moveTimer.stop();
        emit _openDoorsSignal();
    }
}

void Cabin::_saveState(const ssize_t &neededFloor, const ssize_t &currentFloor)
{
    _neededFloor = neededFloor;
    _currentFloor = currentFloor;
    _direction = _currentFloor > _neededFloor ? DOWN : UP;
}
