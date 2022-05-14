/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *loadBox;
    QGridLayout *gridLayout;
    QComboBox *modelsCB;
    QPushButton *loadModelBtn;
    QPushButton *deleteModelBtn;
    QPushButton *deleteModelsBtn;
    QGroupBox *camBox;
    QGridLayout *gridLayout_2;
    QPushButton *addCameraBtn;
    QGridLayout *moveLayout;
    QPushButton *upBtn;
    QPushButton *leftBtn;
    QPushButton *downBtn;
    QPushButton *rigthBtn;
    QComboBox *cameraCB;
    QPushButton *deleteCameraBtn;
    QGroupBox *moveBox;
    QFormLayout *formLayout_3;
    QLabel *dxLbl;
    QDoubleSpinBox *dxDSB;
    QLabel *dyLbl;
    QDoubleSpinBox *dyDSB;
    QLabel *dzLbl;
    QDoubleSpinBox *dzDSB;
    QPushButton *moveBtn;
    QGroupBox *scaleBox;
    QFormLayout *formLayout;
    QLabel *kxLbl;
    QDoubleSpinBox *kxDSB;
    QLabel *kyLbl;
    QDoubleSpinBox *kyDSB;
    QLabel *kzLbl;
    QDoubleSpinBox *kzDSB;
    QPushButton *scaleBtn;
    QGroupBox *rotateBox;
    QFormLayout *formLayout_2;
    QLabel *oxLbl;
    QDoubleSpinBox *oxDSB;
    QLabel *oyLbl;
    QDoubleSpinBox *oyDSB;
    QLabel *ozLbl;
    QDoubleSpinBox *ozDSB;
    QPushButton *rotateBtn;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1229, 703);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        loadBox = new QGroupBox(centralwidget);
        loadBox->setObjectName(QString::fromUtf8("loadBox"));
        gridLayout = new QGridLayout(loadBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        modelsCB = new QComboBox(loadBox);
        modelsCB->setObjectName(QString::fromUtf8("modelsCB"));

        gridLayout->addWidget(modelsCB, 0, 0, 1, 2);

        loadModelBtn = new QPushButton(loadBox);
        loadModelBtn->setObjectName(QString::fromUtf8("loadModelBtn"));
        sizePolicy.setHeightForWidth(loadModelBtn->sizePolicy().hasHeightForWidth());
        loadModelBtn->setSizePolicy(sizePolicy);
        loadModelBtn->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(loadModelBtn, 1, 0, 1, 2);

        deleteModelBtn = new QPushButton(loadBox);
        deleteModelBtn->setObjectName(QString::fromUtf8("deleteModelBtn"));
        sizePolicy.setHeightForWidth(deleteModelBtn->sizePolicy().hasHeightForWidth());
        deleteModelBtn->setSizePolicy(sizePolicy);
        deleteModelBtn->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(deleteModelBtn, 2, 0, 1, 1);

        deleteModelsBtn = new QPushButton(loadBox);
        deleteModelsBtn->setObjectName(QString::fromUtf8("deleteModelsBtn"));
        sizePolicy.setHeightForWidth(deleteModelsBtn->sizePolicy().hasHeightForWidth());
        deleteModelsBtn->setSizePolicy(sizePolicy);
        deleteModelsBtn->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(deleteModelsBtn, 2, 1, 1, 1);


        horizontalLayout_2->addWidget(loadBox);

        camBox = new QGroupBox(centralwidget);
        camBox->setObjectName(QString::fromUtf8("camBox"));
        gridLayout_2 = new QGridLayout(camBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        addCameraBtn = new QPushButton(camBox);
        addCameraBtn->setObjectName(QString::fromUtf8("addCameraBtn"));
        sizePolicy.setHeightForWidth(addCameraBtn->sizePolicy().hasHeightForWidth());
        addCameraBtn->setSizePolicy(sizePolicy);
        addCameraBtn->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(addCameraBtn, 1, 1, 1, 1);

        moveLayout = new QGridLayout();
        moveLayout->setObjectName(QString::fromUtf8("moveLayout"));
        upBtn = new QPushButton(camBox);
        upBtn->setObjectName(QString::fromUtf8("upBtn"));
        sizePolicy.setHeightForWidth(upBtn->sizePolicy().hasHeightForWidth());
        upBtn->setSizePolicy(sizePolicy);
        upBtn->setMinimumSize(QSize(30, 30));
        upBtn->setMaximumSize(QSize(30, 30));

        moveLayout->addWidget(upBtn, 0, 1, 1, 1);

        leftBtn = new QPushButton(camBox);
        leftBtn->setObjectName(QString::fromUtf8("leftBtn"));
        sizePolicy.setHeightForWidth(leftBtn->sizePolicy().hasHeightForWidth());
        leftBtn->setSizePolicy(sizePolicy);
        leftBtn->setMinimumSize(QSize(30, 30));
        leftBtn->setMaximumSize(QSize(30, 30));

        moveLayout->addWidget(leftBtn, 1, 0, 1, 1);

        downBtn = new QPushButton(camBox);
        downBtn->setObjectName(QString::fromUtf8("downBtn"));
        sizePolicy.setHeightForWidth(downBtn->sizePolicy().hasHeightForWidth());
        downBtn->setSizePolicy(sizePolicy);
        downBtn->setMinimumSize(QSize(30, 30));
        downBtn->setMaximumSize(QSize(30, 30));

        moveLayout->addWidget(downBtn, 2, 1, 1, 1);

        rigthBtn = new QPushButton(camBox);
        rigthBtn->setObjectName(QString::fromUtf8("rigthBtn"));
        sizePolicy.setHeightForWidth(rigthBtn->sizePolicy().hasHeightForWidth());
        rigthBtn->setSizePolicy(sizePolicy);
        rigthBtn->setMinimumSize(QSize(30, 30));
        rigthBtn->setMaximumSize(QSize(30, 30));

        moveLayout->addWidget(rigthBtn, 1, 2, 1, 1);


        gridLayout_2->addLayout(moveLayout, 1, 0, 2, 1);

        cameraCB = new QComboBox(camBox);
        cameraCB->setObjectName(QString::fromUtf8("cameraCB"));

        gridLayout_2->addWidget(cameraCB, 0, 0, 1, 2);

        deleteCameraBtn = new QPushButton(camBox);
        deleteCameraBtn->setObjectName(QString::fromUtf8("deleteCameraBtn"));
        sizePolicy.setHeightForWidth(deleteCameraBtn->sizePolicy().hasHeightForWidth());
        deleteCameraBtn->setSizePolicy(sizePolicy);
        deleteCameraBtn->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(deleteCameraBtn, 2, 1, 1, 1);


        horizontalLayout_2->addWidget(camBox);

        moveBox = new QGroupBox(centralwidget);
        moveBox->setObjectName(QString::fromUtf8("moveBox"));
        formLayout_3 = new QFormLayout(moveBox);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        dxLbl = new QLabel(moveBox);
        dxLbl->setObjectName(QString::fromUtf8("dxLbl"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, dxLbl);

        dxDSB = new QDoubleSpinBox(moveBox);
        dxDSB->setObjectName(QString::fromUtf8("dxDSB"));
        dxDSB->setMinimum(-1000.000000000000000);
        dxDSB->setMaximum(1000.000000000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dxDSB);

        dyLbl = new QLabel(moveBox);
        dyLbl->setObjectName(QString::fromUtf8("dyLbl"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, dyLbl);

        dyDSB = new QDoubleSpinBox(moveBox);
        dyDSB->setObjectName(QString::fromUtf8("dyDSB"));
        dyDSB->setMinimum(-1000.000000000000000);
        dyDSB->setMaximum(1000.000000000000000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, dyDSB);

        dzLbl = new QLabel(moveBox);
        dzLbl->setObjectName(QString::fromUtf8("dzLbl"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, dzLbl);

        dzDSB = new QDoubleSpinBox(moveBox);
        dzDSB->setObjectName(QString::fromUtf8("dzDSB"));
        dzDSB->setMinimum(-1000.000000000000000);
        dzDSB->setMaximum(1000.000000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, dzDSB);

        moveBtn = new QPushButton(moveBox);
        moveBtn->setObjectName(QString::fromUtf8("moveBtn"));

        formLayout_3->setWidget(3, QFormLayout::SpanningRole, moveBtn);


        horizontalLayout_2->addWidget(moveBox);

        scaleBox = new QGroupBox(centralwidget);
        scaleBox->setObjectName(QString::fromUtf8("scaleBox"));
        formLayout = new QFormLayout(scaleBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        kxLbl = new QLabel(scaleBox);
        kxLbl->setObjectName(QString::fromUtf8("kxLbl"));

        formLayout->setWidget(0, QFormLayout::LabelRole, kxLbl);

        kxDSB = new QDoubleSpinBox(scaleBox);
        kxDSB->setObjectName(QString::fromUtf8("kxDSB"));
        kxDSB->setMinimum(-100.000000000000000);
        kxDSB->setMaximum(100.000000000000000);
        kxDSB->setSingleStep(0.500000000000000);
        kxDSB->setValue(2.000000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, kxDSB);

        kyLbl = new QLabel(scaleBox);
        kyLbl->setObjectName(QString::fromUtf8("kyLbl"));

        formLayout->setWidget(1, QFormLayout::LabelRole, kyLbl);

        kyDSB = new QDoubleSpinBox(scaleBox);
        kyDSB->setObjectName(QString::fromUtf8("kyDSB"));
        kyDSB->setMinimum(-100.000000000000000);
        kyDSB->setMaximum(100.000000000000000);
        kyDSB->setSingleStep(0.500000000000000);
        kyDSB->setValue(2.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, kyDSB);

        kzLbl = new QLabel(scaleBox);
        kzLbl->setObjectName(QString::fromUtf8("kzLbl"));

        formLayout->setWidget(2, QFormLayout::LabelRole, kzLbl);

        kzDSB = new QDoubleSpinBox(scaleBox);
        kzDSB->setObjectName(QString::fromUtf8("kzDSB"));
        kzDSB->setMinimum(-100.000000000000000);
        kzDSB->setMaximum(100.000000000000000);
        kzDSB->setSingleStep(0.500000000000000);
        kzDSB->setValue(2.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, kzDSB);

        scaleBtn = new QPushButton(scaleBox);
        scaleBtn->setObjectName(QString::fromUtf8("scaleBtn"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, scaleBtn);


        horizontalLayout_2->addWidget(scaleBox);

        rotateBox = new QGroupBox(centralwidget);
        rotateBox->setObjectName(QString::fromUtf8("rotateBox"));
        formLayout_2 = new QFormLayout(rotateBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        oxLbl = new QLabel(rotateBox);
        oxLbl->setObjectName(QString::fromUtf8("oxLbl"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, oxLbl);

        oxDSB = new QDoubleSpinBox(rotateBox);
        oxDSB->setObjectName(QString::fromUtf8("oxDSB"));
        oxDSB->setMinimum(-360.000000000000000);
        oxDSB->setMaximum(360.000000000000000);
        oxDSB->setValue(10.000000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, oxDSB);

        oyLbl = new QLabel(rotateBox);
        oyLbl->setObjectName(QString::fromUtf8("oyLbl"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, oyLbl);

        oyDSB = new QDoubleSpinBox(rotateBox);
        oyDSB->setObjectName(QString::fromUtf8("oyDSB"));
        oyDSB->setMinimum(-360.000000000000000);
        oyDSB->setMaximum(360.000000000000000);
        oyDSB->setValue(10.000000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, oyDSB);

        ozLbl = new QLabel(rotateBox);
        ozLbl->setObjectName(QString::fromUtf8("ozLbl"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, ozLbl);

        ozDSB = new QDoubleSpinBox(rotateBox);
        ozDSB->setObjectName(QString::fromUtf8("ozDSB"));
        ozDSB->setMinimum(-360.000000000000000);
        ozDSB->setMaximum(360.000000000000000);
        ozDSB->setValue(10.000000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, ozDSB);

        rotateBtn = new QPushButton(rotateBox);
        rotateBtn->setObjectName(QString::fromUtf8("rotateBtn"));

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, rotateBtn);


        horizontalLayout_2->addWidget(rotateBox);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_3->addWidget(graphicsView, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab03", nullptr));
        loadBox->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        loadModelBtn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        deleteModelBtn->setText(QCoreApplication::translate("MainWindow", "  \320\243\320\264\320\260\320\273\320\270\321\202\321\214  ", nullptr));
        deleteModelsBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        camBox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        addCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        upBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        leftBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        downBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        rigthBtn->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        deleteCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        moveBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        dxLbl->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        dyLbl->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        dzLbl->setText(QCoreApplication::translate("MainWindow", "dz:", nullptr));
        moveBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        scaleBox->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        kxLbl->setText(QCoreApplication::translate("MainWindow", "kx:", nullptr));
        kyLbl->setText(QCoreApplication::translate("MainWindow", "ky:", nullptr));
        kzLbl->setText(QCoreApplication::translate("MainWindow", "kz:", nullptr));
        scaleBtn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        rotateBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 (\321\203\320\263\320\273\321\213 \320\262 \302\260)", nullptr));
        oxLbl->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276 x:", nullptr));
        oyLbl->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276 y:", nullptr));
        ozLbl->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276 z:", nullptr));
        rotateBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
