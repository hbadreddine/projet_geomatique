



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




vector<vector<Point> > s_contour,cont_filt;


//Taille = 128 * 128. RGB 3 octets
char buffer[128*128*3];
Mat imagebis;
vector<vector<Point> > petitArbre,foret;
vector<Point> centrArbre,centreForet;
vector<RotatedRect> batim,batifiltre;
vegetation arbre;
bati batiment;
//route maroute;

void initGL(TraitementImage projet)
{
    imagebis=projet.exportRoad();
    arbre.triVegeta(projet.exportcontourveget());
    batiment.tribati(projet.exportcontourBati());




    afficheortho mon( &imagebis);
    batiment.drawtotal();
    arbre.drawtotal();
    
}




