#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    _facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    _scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());
    _camInd = 1;

    auto solution(new DrawerFactorySolution<QtDrawerFactory, QGraphicsScene>());
    _drawer = solution->createDrawer(_scene);
}

void MainWindow::updateScene()
{
    auto drawManager = ManagerSolution<DrawManagerCreator>().create();
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto drawCompositeAdapter = DrawCompositeAdapter();

    DrawScene cmd(_drawer, drawManager, sceneManager,
                  std::make_shared<DrawCompositeAdapter>(drawCompositeAdapter));
    _facade->execute(cmd);
}

void MainWindow::checkCamExist()
{
    if (!_cameras.size())
    {
        std::string msg = "No camera found.";
        throw CameraException(msg);
    }
}

void MainWindow::checkModelsExist()
{
    if (!_models.size())
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::checkCamDelete()
{
    if (_cameras.size() <= 1 && _models.size())
    {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw CameraException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();

    auto id = std::make_shared<size_t>(0);
    Vertex location(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    std::shared_ptr<Camera> camera(new Camera(location));
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    AddCamera addCMD(id, camera, sceneManager);

    _facade->execute(addCMD);
    _cameras.push_back(*id);

    updateScene();

    auto cam = ui->cameraCB;

    std::string camName = std::string("cam") + std::to_string(_camInd++);
    cam->addItem(QString(camName.data()));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto file = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", "../lab_03/data");

    if (file.isNull())
        return;

    auto id = std::make_shared<size_t>(0);
    std::string fileName = file.toStdString();

    auto modelLoadModerator = ModeratorSolution<ModelLoadModeratorCreator>().create();
    auto loadManager = ManagerSolution<LoadManagerCreator>().create();
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();

    LoadModel cmd(id, fileName, modelLoadModerator,
                  loadManager, sceneManager);

    try
    {
        _facade->execute(cmd);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    _models.push_back(*id);
    updateScene();
    ui->modelsCB->addItem(QFileInfo(file.toUtf8().data()).fileName());
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    std::size_t id = _models.at(ui->modelsCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    DeleteModel cmd(id, sceneManager);
    _facade->execute(cmd);

    _models.erase(_models.begin() + ui->modelsCB->currentIndex());
    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        std::size_t id = _models.at(i);
        DeleteModel cmd(id, sceneManager);
        _facade->execute(cmd);

        _models.erase(_models.begin() + i);
        ui->modelsCB->removeItem(i);
    }

    updateScene();
}


void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    std::size_t id = _cameras.at(index);
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    SetCamera cmd(id, sceneManager);
    _facade->execute(cmd);

    updateScene();
}


void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    DeleteCamera cmd(id, sceneManager);
    _facade->execute(cmd);

    _cameras.erase(_cameras.begin() + ui->cameraCB->currentIndex());
    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();
    MoveCamera cmd(0, 10, 0, id, sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();
    MoveCamera cmd(-10, 0, 0, id, sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();
    MoveCamera cmd(0, -10, 0, id, sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();
    MoveCamera cmd(10, 0, 0, id, sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();

    MoveModel cmd(
            ui->dxDSB->value(),
            ui->dyDSB->value(),
            ui->dzDSB->value(),
            _models.at(ui->modelsCB->currentIndex()),
            sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();

    ScaleModel cmd(
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value(),
            _models.at(ui->modelsCB->currentIndex()),
            sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    auto sceneManager = ManagerSolution<SceneManagerCreator>().create();
    auto transformManager = ManagerSolution<TransformManagerCreator>().create();

    RotateModel cmd(
            ui->oxDSB->value(),
            ui->oyDSB->value(),
            ui->ozDSB->value(),
            _models.at(ui->modelsCB->currentIndex()),
            sceneManager, transformManager);

    _facade->execute(cmd);
    updateScene();
}

