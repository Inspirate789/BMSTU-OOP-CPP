#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class Door : public QObject
{
    Q_OBJECT;

private:
    enum DoorStatus
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSED
    };

public:
    Door();
    ~Door() = default;

public slots:
    void openingSlot();

private:
    DoorStatus _status;

    QTimer _openingTimer;
    QTimer _closingTimer;
    QTimer _openedTimer;

private slots:
    void _openedSlot();
    void _closingSlot();
    void _closedSlot();

signals:
    void _closedSignal();
};

#endif
