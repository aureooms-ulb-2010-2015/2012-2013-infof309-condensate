#-------------------------------------------------
#
# Project created by QtCreator 2012-12-13T11:16:05
#
#-------------------------------------------------

QT       += core gui opengl xml
ICON = img/play_icon.png

#for c++ 11 support
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = condensate
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += opencv
LIBS += -lv4l2 -lX11 -L ../ -llib309
#LIBS += -lwavelet2d -Lwavelet2s

INCLUDEPATH += /usr/local/lib/ ../lib309
DEPENDPATH += ../lib309
static:unix:TARGETDEPS += ../liblib309.a

SOURCES += \
    Main.cpp \
    MainWindow.cpp \
    CondensateParameterControlWidget.cpp \
    CustomDial.cpp \
    PrecisionTab.cpp \
    DensityTab.cpp \
    SegmentationTab.cpp \
    MatcherTab.cpp \
    FeatureGeneratorTab.cpp \
    CustomToggle.cpp \
    InputOutputTab.cpp \
    CustomSelect.cpp \
    TrustTab.cpp \
    CondensateParameterLoader.cpp


HEADERS += \
    MainWindow.h \
    CondensateParameterControlWidget.h \
    CustomDial.h \
    PrecisionTab.h \
    DensityTab.h \
    SegmentationTab.h \
    MatcherTab.h \
    FeatureGeneratorTab.h \
    CustomToggle.h \
    Algorithm_SynchronizedCondensation.h \
    InputOutputTab.h \
    CustomSelect.h \
    TrustTab.h \
    CondensateParameterLoader.h

RESOURCES += img.qrc

OTHER_FILES += \
    qss/timeControlSlider.qss\
    qss/QComboBox.qss\
    img/play_icon.png\
    img/pause_icon.png \
    qss/QComboBoxDropDown.qss \
    xml/facedata.xml \
    xml/haarcascade_frontalface_alt.xml \
    xml/haarcascade_frontalface_default.xml \
    xml/lpbcascade_frontalface.xml \
    xml/haarcascade_eye_tree_eyeglasses.xml \
    data/greyfish.png \
    data/bigfish.png \
    data/yellowfish.png \
    qss/CustomButton.qss \
    img/parameter.png
