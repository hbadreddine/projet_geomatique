#ifndef VEGETATION_H
#define VEGETATION_H
#include "bati.h"
#include <vector>

class vegetation
{
public:
    vegetation();
    void triVegeta(vector< vector<Point> > contourVeget);
    int drawCylindre(float base, float height);
    void drawArbre(float x, float y, float taille);
    void drawBranche(int p, float taille);
    bool myDoublon(vector<Point> list, Point lePoint);
    void drawtotal();
private:
    vector<Point> centrArbre,centreForet;
};

#endif // VEGETATION_H
