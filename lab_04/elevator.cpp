#include "elevator.h"
#include <QPalette>

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    _controller.setStyleSheet("background-color:green;");

    QObject::connect(&_cabin, SIGNAL(_floorPassedSignal(ssize_t,Direction)),
                     &_controller, SLOT(floorPassedSlot(ssize_t,Direction)));
    QObject::connect(&_controller, SIGNAL(_startMovingSignal(ssize_t&,ssize_t&,Direction&)),
                     &_cabin, SLOT(startMovingSlot(ssize_t&,ssize_t&,Direction&)));
    QObject::connect(&_controller, SIGNAL(_cabinStoppedSignal(bool,ssize_t,ssize_t)),
                     &_cabin, SLOT(stoppedSlot(bool,ssize_t,ssize_t)));
}

QWidget *Elevator::widget()
{
    return &_controller;
}
