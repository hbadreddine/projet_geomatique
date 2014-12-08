#ifndef BATI_H
#define BATI_H
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <QList>
#include <list>
#include <QImage>
#include <QGLWidget>
#include <QtOpenGL>

using namespace cv;
class bati
{
public:
    /**
     * \brief      Constructeur de la classe bati
     * \details    Classe permettant de tracer les batiments en OpenGL
     */
    bati();
    /**
     * \brief     Tri les batiments en fonction de leur aire et stocke cette aire
     *
     *
     * \param[in] contourbati Liste des batiments
     *
     */
    void tribati(vector<RotatedRect> contourbati);
    /**
     * \brief     Charge les textures
     * \details   Charge et stocke une liste de textures à partir d'images
     *
     */
    void loadTexture();
    /**
     * \brief     Trace un batiment
     * \details   A partir de 4 point trace un batiment avec un toit et 4 murs, des textures sont appliquées en fonction de la taille du batiment
     *
     * \param[in] myforme[] Tableau des 4 points du batiment
     * \param[in] hauteur   Hauteur du batiment calculé en fonction de son aire
     */
    void drawgeneral(Point2f[], int hauteur);
    /**
     * \brief     Trace les batiments
     *
     */
    void drawtotal();




private:
    vector<RotatedRect> batifiltre;
    vector<int> aire;
    GLuint _texture[7];
};

#endif // BATI_H
