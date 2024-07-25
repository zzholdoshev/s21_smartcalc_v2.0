QT += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/Controller.cpp \
    Model/checker.cpp \
    Model/parser.cpp \
    QCustomPlot/qcustomplot.cpp \
    View/graph_window.cpp \
    View/mainwindow.cpp \
    main.cpp \

HEADERS += \
    Controller/Controller.h \
    Model/Model.h \
    QCustomPlot/qcustomplot.h \
    View/common.h \
    View/graph_window.h \
    View/mainwindow.h \

FORMS += \
    View/graph_window.ui \
    View/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
