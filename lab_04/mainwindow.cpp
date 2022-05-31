#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(290, 500);
    this->setWindowTitle("Elevator control panel");
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->ui->centralwidget->setLayout(_layout.get());
    _layout->addWidget(_elevator.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

