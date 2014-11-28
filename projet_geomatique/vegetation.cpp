#include "vegetation.h"
float r3s2=sqrt(3)/2;
vegetation::vegetation()
{

}

void vegetation::triVegeta(vector< vector<Point> > contourVeget){
    float x_centre,y_centre;
    for(int i=0;i<contourVeget.size();i++){
        x_centre=0;
        y_centre=0;
        for(int j=0;j<contourVeget.at(i).size();j++){
            x_centre+=contourVeget.at(i).at(j).x;
            y_centre+=contourVeget.at(i).at(j).y;}
        x_centre=x_centre/contourVeget.at(i).size();
        y_centre=y_centre/contourVeget.at(i).size();
        Point petitpoint(x_centre,y_centre);
        if (contourVeget.at(i).size() > 40 ){
            if (myDoublon(centreForet, petitpoint)){
                centreForet.push_back(petitpoint);}}
        else{
            if (myDoublon(centrArbre, petitpoint)){
                centrArbre.push_back(petitpoint);}}
    }

}

void vegetation::drawtotal(){
    for(int i=0;i< centrArbre.size();i++){
        drawArbre(centrArbre.at(i).x/5,centrArbre.at(i).y/5,0.4);
    }
    for(int i=0;i< centreForet.size();i++){
        drawArbre(centreForet.at(i).x/5,centreForet.at(i).y/5,0.4);
    }
}

bool vegetation::myDoublon(vector<Point> list, Point lePoint){

    float distan;
    for (int i=0;i<list.size();i++)
    {
        distan =abs(list.at(i).x-lePoint.x)+ abs(list.at(i).y-lePoint.y);
        if(distan<10 )
            return false;
    }

    return true;

}
int vegetation::drawCylindre(float base, float height){
    GLUquadric *obj = gluNewQuadric();



    gluCylinder(obj, base,base-(0.2*base), height, 20,20);

    return 0;
}

void vegetation::drawArbre(float x,float y,float taille){
    glPushMatrix();
    glTranslatef(x,y,0);
    glColor3f(0.36, 0.24, 0.07);
    glPushMatrix();
    drawCylindre(taille/2,taille*5);
    glPopMatrix();
    drawBranche(4, taille/4);
    glPopMatrix();
}

void vegetation::drawBranche(int p,float taille){
    float x,y;
    if (p==1){

        for(int i=0;i<3;i++){
            if (i==0){
                x=1,y=0;
            }else if(i==1){
                x=-0.5,y=r3s2;
            }else {
                x=-0.5,y=-r3s2;
            }

            glPushMatrix();
            glColor3f(0.27,0.55,0);
            glTranslatef(0,0,taille*5);
            glRotatef(-40, x,y,0.0);
            drawCylindre(taille*1.7,taille*7);
            glPopMatrix();

        }
        return;
    }

    for(int i=0;i<3;i++){
        if (i==0){
            x=1,y=0;
        }else if(i==1){
            x=-0.5,y=r3s2;
        }else {
            x=-0.5,y=-r3s2;
        }

        glPushMatrix();
        glColor3f(0.36+(7-p)*0.05, 0.24+(7-p)*0.05, 0.07+(7-p)*0.05);
        glTranslatef(0,0,taille*5*p);
        glRotatef(-40, x,y,0.0);
        drawCylindre(taille*p/4,taille*p*5);
        drawBranche( p-1,taille);
        glPopMatrix();

    }

}
