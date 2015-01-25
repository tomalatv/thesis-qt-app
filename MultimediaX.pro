# -------------------------------------------------
# Project created by QtCreator 2009-05-08T08:26:49
# -------------------------------------------------

TARGET = MultimediaX
LIBS += C:\Gradu\Qt\lib\libvlccore.dll \
    C:\Gradu\Qt\lib\libvlc.dll\

TEMPLATE = app

SOURCES += testdialog.cpp \
    main.cpp \
    multimediax.cpp

HEADERS += multimediax.h \
    testdialog.h \
    vlc/libvlc_events.h \
    vlc/libvlc.h \
    vlc/libvlc_structures.h \
    vlc/mediacontrol.h \
    vlc/mediacontrol_structures.h \
    vlc/libvlc_vlm.h \
    trans.h

FORMS += testdialog.ui \
    multimediax.ui
