TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
INCLUDEPATH += /usr/local/include \
               /usr/local/include/opencv4/opencv2 \
               /usr/local/include/opencv4 \

LIBS += /usr/local/lib/libopencv_*.so \

QMAKE_LFLAGS += -pthread
