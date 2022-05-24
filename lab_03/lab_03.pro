# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_03

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS = \
    adapters/composite/compositeadapter.h \
    adapters/composite/drawcompositeadapter.h \
    adapters/model/drawcarcassmodeladapter.h \
    adapters/model/modeladapter.h \
    adapters/baseadapter.h \
    commands/basecommand.h \
    commands/cameracommand.h \
    commands/modelcommand.h \
    commands/modelscommand.h \
    commands/scenecommand.h \
    drawer/abstractdrawerfactory.h \
    drawer/basedrawer.h \
    drawer/drawerfactorysolution.h \
    drawer/drawerfactorysolution.hpp \
    drawer/qtdrawer.h \
    drawer/qtdrawerfactory.h \
    exceptions/exceptions.h \
    facade/facade.h \
    load/builders/camera/basecamerabuilder.h \
    load/builders/camera/camerabuilder.h \
    load/builders/model/basemodelbuilder.h \
    load/builders/model/modelbuilder.h \
    load/builders/scene/basescenebuilder.h \
    load/builders/scene/scenebuilder.h \
    load/builders/basebuilder.h \
    load/directors/camera/basecamerabuilddirector.h \
    load/directors/camera/filecamerabuilddirector.h \
    load/directors/model/basemodelbuilddirector.h \
    load/directors/model/filemodelbuilddirector.h \
    load/directors/readers/basecarcassmodelreader.h \
    load/directors/readers/filecarcassmodelreader.h \
    load/directors/scene/basescenebuilddirector.h \
    load/directors/scene/filescenebuilddirector.h \
    load/directors/basedirector.h \
    load/moderators/camera/cameraloadmoderator.h \
    load/moderators/creators/cameraloadmoderatorcreator.h \
    load/moderators/creators/modelloadmoderatorcreator.h \
    load/moderators/creators/moderatorsolution.h \
    load/moderators/creators/sceneloadmoderatorcreator.h \
    load/moderators/model/modelloadmoderator.h \
    load/moderators/scene/sceneloadmoderator.h \
    load/moderators/baseloadmoderator.h \
    managers/creators/drawmanagercreator.h \
    managers/creators/loadmanagercreator.h \
    managers/creators/managersolution.h \
    managers/creators/scenemanagercreator.h \
    managers/creators/transformmanagercreator.h \
    managers/draw/drawmanager.h \
    managers/load/loadmanager.h \
    managers/scene/scenemanager.h \
    managers/transform/transformmanager.h \
    managers/basemanager.h \
    matrix/errors/errors.hpp \
    matrix/iterator/const_matrix_iterator.h \
    matrix/iterator/const_matrix_iterator.hpp \
    matrix/iterator/matrix_iterator.h \
    matrix/iterator/matrix_iterator.hpp \
    matrix/matrix/matrix.h \
    matrix/matrix/matrix.hpp \
    matrix/matrix/matrix_base.hpp \
    objects/invisibleobject/camera.h \
    objects/invisibleobject/invisibleobject.h \
    objects/visibleobject/carcassmodel/carcassmodel.h \
    objects/visibleobject/carcassmodel/link.h \
    objects/visibleobject/carcassmodel/modelstructure.h \
    objects/visibleobject/carcassmodel/vertex.h \
    objects/visibleobject/basemodel.h \
    objects/visibleobject/visibleobject.h \
    objects/composite.h \
    objects/object.h \
    scene/scene.h \
    mainwindow.h

SOURCES = \
   adapters/composite/drawcompositeadapter.cpp \
   adapters/model/drawcarcassmodeladapter.cpp \
   commands/basecommand.cpp \
   commands/cameracommand.cpp \
   commands/modelcommand.cpp \
   commands/modelscommand.cpp \
   commands/scenecommand.cpp \
   drawer/qtdrawer.cpp \
   drawer/qtdrawerfactory.cpp \
   facade/facade.cpp \
   load/builders/camera/camerabuilder.cpp \
   load/builders/model/modelbuilder.cpp \
   load/builders/scene/scenebuilder.cpp \
   load/directors/camera/filecamerabuilddirector.cpp \
   load/directors/model/filemodelbuilddirector.cpp \
   load/directors/readers/basecarcassmodelreader.cpp \
   load/directors/readers/filecarcassmodelreader.cpp \
   load/directors/scene/filescenebuilddirector.cpp \
   load/moderators/camera/cameraloadmoderator.cpp \
   load/moderators/creators/cameraloadmoderatorcreator.cpp \
   load/moderators/creators/modelloadmoderatorcreator.cpp \
   load/moderators/creators/sceneloadmoderatorcreator.cpp \
   load/moderators/model/modelloadmoderator.cpp \
   load/moderators/scene/sceneloadmoderator.cpp \
   load/moderators/baseloadmoderator.cpp \
   managers/creators/drawmanagercreator.cpp \
   managers/creators/loadmanagercreator.cpp \
   managers/creators/scenemanagercreator.cpp \
   managers/creators/transformmanagercreator.cpp \
   managers/draw/drawmanager.cpp \
   managers/load/loadmanager.cpp \
   managers/scene/scenemanager.cpp \
   managers/transform/transformmanager.cpp \
   matrix/errors/errors.cpp \
   matrix/matrix/matrix_base.cpp \
   objects/invisibleobject/camera.cpp \
   objects/visibleobject/carcassmodel/carcassmodel.cpp \
   objects/visibleobject/carcassmodel/link.cpp \
   objects/visibleobject/carcassmodel/modelstructure.cpp \
   objects/visibleobject/carcassmodel/vertex.cpp \
   objects/visibleobject/basemodel.cpp \
   objects/composite.cpp \
   objects/object.cpp \
   scene/scene.cpp \
   main.cpp \
   mainwindow.cpp

FORMS += \
    mainwindow.ui

INCLUDEPATH = \
    . \
    adapters \
    adapters/composite \
    adapters/model \
    commands \
    drawer \
    exceptions \
    facade \
    load/builders \
    load/builders/camera \
    load/builders/model \
    load/builders/scene \
    load/directors \
    load/directors/camera \
    load/directors/model \
    load/directors/scene \
    load/directors/readers \
    load/moderators \
    load/moderators/camera \
    load/moderators/creators \
    load/moderators/model \
    load/moderators/scene \
    managers \
    managers/creators \
    managers/draw \
    managers/load \
    managers/scene \
    managers/transform \
    matrix \
    matrix/errors \
    matrix/iterator \
    matrix/matrix \
    objects \
    objects/invisibleobject \
    objects/visibleobject \
    objects/visibleobject/carcassmodel \
    scene

#DEFINES =

DISTFILES += \
    data/cone.txt \
    data/cube.txt \
    data/tesseract.txt

