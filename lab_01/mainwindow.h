#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "errors.h"

#define INPUT_FILE "input.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MoveButton_clicked();
    void on_ScaleButton_clicked();
    void on_RotateButton_clicked();
    void on_LoadFigureButton_clicked();
    error_t DrawScene(void);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
