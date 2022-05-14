# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_03

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS = \
   $$PWD/adapters/composite/compositeadapter.h \
   $$PWD/adapters/composite/drawcompositeadapter.h \
   $$PWD/adapters/model/drawcarcassmodeladapter.h \
   $$PWD/adapters/model/modeladapter.h \
   $$PWD/adapters/baseadapter.h \
   $$PWD/commands/basecommand.h \
   $$PWD/commands/cameracommand.h \
   $$PWD/commands/modelcommand.h \
   $$PWD/commands/scenecommand.h \
   $$PWD/creators/crcreator.h \
   $$PWD/creators/creators.h \
   $$PWD/creators/solution.h \
   $$PWD/creators/solution.hpp \
   $$PWD/drawer/abstractdrawerfactory.h \
   $$PWD/drawer/basedrawer.h \
   $$PWD/drawer/drawerfactorydirector.h \
   $$PWD/drawer/drawerfactorysolution.h \
   $$PWD/drawer/drawerfactorysolution.hpp \
   $$PWD/drawer/qtdrawer.h \
   $$PWD/drawer/qtdrawerfactory.h \
   $$PWD/exceptions/exceptions.h \
   $$PWD/facade/facade.h \
   $$PWD/load/builders/camera/basecamerabuilder.h \
   $$PWD/load/builders/camera/camerabuilder.h \
   $$PWD/load/builders/model/basemodelbuilder.h \
   $$PWD/load/builders/model/modelbuilder.h \
   $$PWD/load/builders/scene/basescenebuilder.h \
   $$PWD/load/builders/scene/scenebuilder.h \
   $$PWD/load/builders/basebuilder.h \
   $$PWD/load/directors/camera/basecamerabuilddirector.h \
   $$PWD/load/directors/camera/filecamerabuilddirector.h \
   $$PWD/load/directors/model/basemodelbuilddirector.h \
   $$PWD/load/directors/model/filemodelbuilddirector.h \
   $$PWD/load/directors/scene/basescenebuilddirector.h \
   $$PWD/load/directors/scene/filescenebuilddirector.h \
   $$PWD/load/directors/basedirector.h \
   $$PWD/load/moderators/camera/cameraloadmoderator.h \
   $$PWD/load/moderators/model/modelloadmoderator.h \
   $$PWD/load/moderators/scene/sceneloadmoderator.h \
   $$PWD/load/moderators/baseloadmoderator.h \
   $$PWD/managers/draw/drawmanager.h \
   $$PWD/managers/load/loadmanager.h \
   $$PWD/managers/scene/scenemanager.h \
   $$PWD/managers/transform/transformmanager.h \
   $$PWD/managers/basemanager.h \
   $$PWD/matrix/allocation_data.hpp \
   $$PWD/matrix/const_iterator.h \
   $$PWD/matrix/const_iterator.hpp \
   $$PWD/matrix/funcs.h \
   $$PWD/matrix/iterator.h \
   $$PWD/matrix/iterator.hpp \
   $$PWD/matrix/iterator_exceptions.h \
   $$PWD/matrix/matrix.h \
   $$PWD/matrix/matrix_base.h \
   $$PWD/matrix/matrix_constructors.hpp \
   $$PWD/matrix/matrix_exceptions.h \
   $$PWD/matrix/matrix_iterator.hpp \
   $$PWD/matrix/matrix_math.hpp \
   $$PWD/matrix/matrix_operators.hpp \
   $$PWD/matrix/matrix_row.hpp \
   $$PWD/objects/invisibleobject/camera.h \
   $$PWD/objects/invisibleobject/invisibleobject.h \
   $$PWD/objects/visibleobject/carcassmodel/carcassmodel.h \
   $$PWD/objects/visibleobject/carcassmodel/link.h \
   $$PWD/objects/visibleobject/carcassmodel/modelstructure.h \
   $$PWD/objects/visibleobject/carcassmodel/vertex.h \
   $$PWD/objects/visibleobject/basemodel.h \
   $$PWD/objects/visibleobject/visibleobject.h \
   $$PWD/objects/composite.h \
   $$PWD/objects/object.h \
   $$PWD/scene/scene.h \
   $$PWD/mainwindow.h \

SOURCES = \
   $$PWD/adapters/composite/drawcompositeadapter.cpp \
   $$PWD/adapters/model/drawcarcassmodeladapter.cpp \
   $$PWD/commands/cameracommand.cpp \
   $$PWD/commands/modelcommand.cpp \
   $$PWD/commands/scenecommand.cpp \
   $$PWD/drawer/drawerfactorydirector.cpp \
   $$PWD/drawer/qtdrawer.cpp \
   $$PWD/drawer/qtdrawerfactory.cpp \
   $$PWD/facade/facade.cpp \
   $$PWD/load/builders/camera/camerabuilder.cpp \
   $$PWD/load/builders/model/modelbuilder.cpp \
   $$PWD/load/builders/scene/scenebuilder.cpp \
   $$PWD/load/directors/camera/filecamerabuilddirector.cpp \
   $$PWD/load/directors/model/filemodelbuilddirector.cpp \
   $$PWD/load/directors/scene/filescenebuilddirector.cpp \
   $$PWD/load/moderators/camera/cameraloadmoderator.cpp \
   $$PWD/load/moderators/model/modelloadmoderator.cpp \
   $$PWD/load/moderators/scene/sceneloadmoderator.cpp \
   $$PWD/load/moderators/baseloadmoderator.cpp \
   $$PWD/managers/draw/drawmanager.cpp \
   $$PWD/managers/load/loadmanager.cpp \
   $$PWD/managers/scene/scenemanager.cpp \
   $$PWD/managers/transform/transformmanager.cpp \
   $$PWD/matrix/funcs.cpp \
   $$PWD/matrix/matrix_base.cpp \
   $$PWD/objects/invisibleobject/camera.cpp \
   $$PWD/objects/visibleobject/carcassmodel/carcassmodel.cpp \
   $$PWD/objects/visibleobject/carcassmodel/link.cpp \
   $$PWD/objects/visibleobject/carcassmodel/modelstructure.cpp \
   $$PWD/objects/visibleobject/carcassmodel/vertex.cpp \
   $$PWD/objects/visibleobject/basemodel.cpp \
   $$PWD/objects/composite.cpp \
   $$PWD/objects/object.cpp \
   $$PWD/scene/scene.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp

FORMS += \
    mainwindow.ui

INCLUDEPATH = \
    $$PWD/. \
    $$PWD/adapters \
    $$PWD/adapters/composite \
    $$PWD/adapters/model \
    $$PWD/commands \
    $$PWD/creators \
    $$PWD/drawer \
    $$PWD/exceptions \
    $$PWD/facade \
    $$PWD/load/builders \
    $$PWD/load/builders/camera \
    $$PWD/load/builders/model \
    $$PWD/load/builders/scene \
    $$PWD/load/directors \
    $$PWD/load/directors/camera \
    $$PWD/load/directors/model \
    $$PWD/load/directors/scene \
    $$PWD/load/moderators \
    $$PWD/load/moderators/camera \
    $$PWD/load/moderators/model \
    $$PWD/load/moderators/scene \
    $$PWD/managers \
    $$PWD/managers/draw \
    $$PWD/managers/load \
    $$PWD/managers/scene \
    $$PWD/managers/transform \
    $$PWD/matrix \
    $$PWD/objects \
    $$PWD/objects/invisibleobject \
    $$PWD/objects/visibleobject \
    $$PWD/objects/visibleobject/carcassmodel \
    $$PWD/scene

#DEFINES =

DISTFILES += \
    data/cone.txt \
    data/cube.txt \
    data/tesseract.txt

