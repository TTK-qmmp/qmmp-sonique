include(../../plugins.pri)

QT += opengl
TARGET = $$PLUGINS_PREFIX/Visual/sonique

HEADERS += soniqueplugin.h \
           soniquewidget.h \
           visual.h \
           kiss_fft.h \
           visualsoniquefactory.h

SOURCES += soniqueplugin.cpp \
           soniquewidget.cpp \
           kiss_fft.c \
           visualsoniquefactory.cpp

unix{
    target.path = $$PLUGIN_DIR/Visual
    INSTALLS += target
}
