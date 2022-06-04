#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT;

    enum ButtonStatus
    {
        ACTIVE,
        NOT_ACTIVE
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() = default;

    void setFloor(const ssize_t &floor);

public slots:
    void unpressed();

signals:
    void pressedSignal(ssize_t floor);
    void unpressedSignal();

private:
    ButtonStatus _status;
    ssize_t _buttonFloor;

private slots:
    void _pressedSlot();
};

#endif
