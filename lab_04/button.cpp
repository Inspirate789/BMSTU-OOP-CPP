#include "button.h"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()),
                     this, SLOT(_pressedSlot()));
    QObject::connect(this, SIGNAL(unpressedSignal()),
                     this, SLOT(_unpressedSlot()));

    _status = NOT_ACTIVE;
    _buttonFloor = 1;

    setStyleSheet("border-style: outset;"
                  "border-width: 2px;"
                  "border-radius: 10px;"
                  "border-color: beige;"
                  "font: bold 14px;"
                  "padding: 6px;");
}

void Button::setFloor(const ssize_t &floor)
{
    _buttonFloor = floor;
}

void Button::_pressedSlot()
{
    if (_status == NOT_ACTIVE)
    {
        this->setStyleSheet("background-color:red;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-radius: 10px;"
                            "border-color: beige;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        _status = ACTIVE;
        this->setDisabled(true);
        emit pressedSignal(_buttonFloor);
    }
}

void Button::_unpressedSlot()
{
    if (_status == ACTIVE)
    {
        this->setStyleSheet("background-color:green;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-radius: 10px;"
                            "border-color: beige;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        _status = NOT_ACTIVE;
        this->setDisabled(false);
    }
}
