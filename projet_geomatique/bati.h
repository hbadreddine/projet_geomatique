#ifndef BATI_H
#define BATI_H
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>    // Header File For The OpenGL32 Library
#include <GL/glu.h>
#include <iostream>
#include <QList>
#include <list>

using namespace cv;
class bati
{
public:
    bati();
    bati(int );

    void drawgeneral(Point2f[]);
    void drawtotal( );
    void tribati(vector<RotatedRect> contourbati);
private:
    vector<RotatedRect> batifiltre;
};

#endif // BATI_H
