#include "standardCamera.h"
#include "viewer.h"
#include "cameraViewer.h"

#include <QApplication>
#include <QGLViewer/manipulatedCameraFrame.h>

int main(int argc, char** argv)
{
  QApplication application(argc,argv);


  StandardCamera* sc = new StandardCamera();
  Viewer viewer(sc);
  

  viewer.setWindowTitle("standardCamera");


  viewer.show();

  return application.exec();
}
