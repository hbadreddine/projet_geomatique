#include "cameraViewer.h"
#include "bati.h"
#include "initgl.h"
#include "traitementimage.h"


using namespace qglviewer;

CameraViewer::CameraViewer(Camera* camera) : c(camera) {};

Mat image1 = imread("/home/gtsi/Téléchargements/imageSat.png");
TraitementImage projet1(&image1);

void CameraViewer::draw()
{
   initGL(projet1);
  
  //b.draw();

  
}

void CameraViewer::init()
{
  
    // Make near and far planes much further from scene in order not to clip c's display.
	camera()->setZClippingCoefficient(10.0);
    camera()->setViewDirection(qglviewer::Vec(0.0, -1.0, -8.0));
    showEntireScene();
  

  // Enable semi-transparent culling planes
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
