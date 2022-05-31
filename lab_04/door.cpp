#include "door.h"
#include "controller.h"

Door::Door()
{
    _status = CLOSED;

    QObject::connect(&_openingTimer, SIGNAL(timeout()),
                     this, SLOT(_openedSlot()));
    QObject::connect(&_openedTimer,  SIGNAL(timeout()),
                     this, SLOT(_closingSlot()));
    QObject::connect(&_closingTimer, SIGNAL(timeout()),
                     this, SLOT(_closedSlot()));
}

void Door::openingSlot()
{
    if (_status == CLOSED || _status == CLOSING)
    {
        qDebug() << "Двери открываются.";
        _status = OPENING;

        if (_status == CLOSED)
            _openingTimer.start(DOORS_TIME);
        else
        {
            auto timer = _closingTimer.remainingTime();
            _closingTimer.stop();
            _openingTimer.start(DOORS_TIME - timer);
        }
    }
}

void Door::_openedSlot()
{
    if (_status == OPENING)
    {
        _status = OPEN;
        qDebug() << "Двери открыты!";
        _openedTimer.start(DOORS_TIME);
    }
}

void Door::_closingSlot()
{
    if (_status == OPEN)
    {
        _status = CLOSING;
        qDebug() << "Двери закрываются.";
        _closingTimer.start(DOORS_TIME);
    }
}

void Door::_closedSlot()
{
    if (_status == CLOSING)
    {
        _status = CLOSED;
        qDebug() << "Двери закрыты.";
        emit _closedSignal();
    }
}
