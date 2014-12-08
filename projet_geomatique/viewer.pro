TARGET = viewer
CONFIG *= qt opengl release
QT *= opengl xml

HEADERS = afficheortho.h vegetation.h percepunit.h standardCamera.h cameraViewer.h viewer.h bati.h initgl.h traitementimage.h texture.h classification.h
SOURCES = afficheortho.cpp vegetation.cpp percepunit.cpp standardCamera.cpp cameraViewer.cpp viewer.cpp bati.cpp initgl.cpp traitementimage.cpp main.cpp texture.cpp classification.cpp

# Linux
INCLUDEPATH *= /home/inf0phile/Téléchargements/libQGLViewer-2.3.17
LIBS *= -L/home/inf0phile/Téléchargements/libQGLViewer-2.3.17/QGLViewer -lQGLViewer -lGL -lGLU


INCLUDEPATH += -L/usr/lib/
INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann