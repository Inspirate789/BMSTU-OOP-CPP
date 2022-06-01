#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(_layout.get());

    QObject::connect(this, SIGNAL(_floorPassedSignal(ssize_t,Direction)),
                     this, SLOT(floorPassedSlot(ssize_t,Direction)));
    QObject::connect(this, SIGNAL(_controllerStoppedSignal()),
                     this, SLOT(controllerStoppedSlot()));

    _status = FREE;
    _currentFloor = 1;
    _neededFloor = 1;
    _direction = STOP;

    for (int i = 0; i < FLOOR_COUNT; i++)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->setFloor(FLOOR_COUNT - i);
        btn->setText(QString::number(FLOOR_COUNT - i));

        _buttons.insert(_buttons.begin(), btn);
        _layout->addWidget(btn.get());

        _visitedFloors.push_back(true);

        QObject::connect(btn.get(), SIGNAL(pressedSignal(ssize_t)),
                         this, SLOT(newTargetSlot(ssize_t)));
    }
}

void Controller::newTargetSlot(ssize_t floor)
{
    _visitedFloors[floor - 1] = false;

    if (_status != GET_TARGET)
    {
        _status = GET_TARGET;
        _targetExist(floor);
        _neededFloor = floor;

        if (_currentFloor == _neededFloor)
            emit _floorPassedSignal(_currentFloor, _direction);
        else
        {
            _direction = _neededFloor > _currentFloor ? UP : DOWN;
            emit _getTargetSignal(_neededFloor, _currentFloor);
        }
    }
}

void Controller::controllerStoppedSlot()
{
    if (_status == BUSY)
    {
        _status = FREE;
        emit _cabinStoppedSignal(true, _currentFloor);
    }
}

void Controller::floorPassedSlot(ssize_t floor, Direction direction)
{
    if (_status == GET_TARGET || _status == BUSY)
    {
        _status = BUSY;
        _currentFloor = floor;
        _direction = direction;

        if (_currentFloor == _neededFloor)
        {
            emit _buttons[floor - 1]->unpressedSignal();
            _visitedFloors[floor - 1] = true;

            if (_targetExist(_neededFloor))
                emit _cabinStoppedSignal(false, _currentFloor, _neededFloor);
            else
                emit _controllerStoppedSignal();
        }
    }
}

bool Controller::_targetExist(ssize_t &newFloor)
{
    int direction = _direction != STOP ? _direction : DOWN;

    for (int i = _currentFloor - 1; i >= 0 && i < FLOOR_COUNT; i += direction)
    {
        if (!_visitedFloors[i])
        {
            newFloor = i + 1;
            return true;
        }
    }

    for (int i = _currentFloor - 1; i >= 0 && i < FLOOR_COUNT; i += -direction)
    {
        if (!_visitedFloors[i])
        {
            newFloor = i + 1;
            return true;
        }
    }

    return false;
}
