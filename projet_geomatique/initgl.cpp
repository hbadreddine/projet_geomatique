



#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <math.h>
#include <QVector3D>
#include <QQuaternion>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "initgl.h"

#include "bati.h"
#include "traitementimage.h"
#include "afficheortho.h"
#include "vegetation.h"
using namespace std;




Mat imagebis;

vegetation arbre;
bati batiment;


void initGL(TraitementImage projet)
{

    imagebis=projet.exportRoad();
    arbre.triVegeta(projet.exportcontourveget());
    batiment.tribati(projet.exportcontourBati());
    batiment.loadTexture();




    //////// AFFICHAGE OPENGL////////////

    afficheortho mon( &imagebis);
    batiment.drawtotal();
    arbre.drawtotal();
    }


