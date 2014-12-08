#include "afficheortho.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace cv;
using namespace std;

afficheortho::afficheortho(Mat *image)
{
    Mat imagebis = *image;
    Mat channel[3];
    float rouge, vert, bleu;

    split (imagebis, channel);
    glBegin(GL_QUADS);

    for (int j = 0; j < channel[2].rows; j++){

        for (int i = 0; i < channel[2].cols; i++){

            rouge = (int)channel[2].at<uchar>(j,i);
            vert = (int)channel[1].at<uchar>(j,i);
            bleu = (int)channel[0].at<uchar>(j,i);

            glColor3f(rouge / 256, vert / 256, bleu / 256);

            glVertex3f(i/5, j/5, 0);
            glVertex3f(i/5, (j + 1)/5, 0);
            glVertex3f((i + 1)/5,( j + 1)/5, 0);
            glVertex3f((i + 1)/5, j/5, 0);

        }
    }

    glEnd();

}
