#include <cstdio>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasks_handling.h"
#include "figure.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, 1, 1);
}

MainWindow::~MainWindow()
{
    task_t cur_task;
    cur_task.action = DESTROY;
    HandleTask(cur_task);

    delete ui;
}

error_t MainWindow::DrawScene(void)
{
    scene_t scene;
    scene.canvas = ui->graphicsView->scene();
    scene.width = ui->graphicsView->width();
    scene.height = ui->graphicsView->height();

    task_t cur_task;
    cur_task.action = DRAW;
    cur_task.attribute.scene = scene;

    error_t error_code = HandleTask(cur_task);

    return error_code;
}

void MainWindow::on_LoadFigureButton_clicked()
{
    task_t cur_task;
    cur_task.action = LOAD;
    cur_task.attribute.filename = INPUT_FILE;

    error_t error_code = HandleTask(cur_task);

    if (error_code != SUCCESS)
    {
        HandleError(error_code);
        return;
    }

    error_code = DrawScene();

    if (error_code != SUCCESS)
        HandleError(error_code);
}

void MainWindow::on_MoveButton_clicked()
{
    move_t coefs;
    coefs.dx = ui->DxField->value();
    coefs.dy = ui->DyField->value();
    coefs.dz = ui->DzField->value();

    task_t cur_task;
    cur_task.action = MOVE;
    cur_task.attribute.move_coefs = coefs;

    error_t error_code = HandleTask(cur_task);

    if (error_code != SUCCESS)
    {
        HandleError(error_code);
        return;
    }

    error_code = DrawScene();

    if (error_code != SUCCESS)
        HandleError(error_code);
}

void MainWindow::on_ScaleButton_clicked()
{
    scale_t coefs;
    coefs.kx = ui->KxField->value();
    coefs.ky = ui->KyField->value();
    coefs.kz = ui->KzField->value();

    task_t cur_task;
    cur_task.action = SCALE;
    cur_task.attribute.scale_coefs = coefs;

    error_t error_code = HandleTask(cur_task);

    if (error_code != SUCCESS)
    {
        HandleError(error_code);
        return;
    }

    error_code = DrawScene();

    if (error_code != SUCCESS)
        HandleError(error_code);
}

void MainWindow::on_RotateButton_clicked()
{
    rotate_t coefs;
    coefs.ax = ui->AxField->value();
    coefs.ay = ui->AyField->value();
    coefs.az = ui->AzField->value();

    task_t cur_task;
    cur_task.action = ROTATE;
    cur_task.attribute.rotate_coefs = coefs;

    error_t error_code = HandleTask(cur_task);

    if (error_code != SUCCESS)
    {
        HandleError(error_code);
        return;
    }

    error_code = DrawScene();

    if (error_code != SUCCESS)
        HandleError(error_code);
}
