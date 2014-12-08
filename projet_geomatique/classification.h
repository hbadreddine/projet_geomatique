#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace cv;
using namespace std;

class classification
{
    // externally accessible class members?
public:

    // constructor method
    /**
    * \brief:      Fonction de classification d'une image
    *
    * \detail:     La fonction effectue une classification de l'image
    *
    * \param[in]    ROI    Image en entrée
    *
    */
    classification(Mat ROI, Mat alpha, int ix, int iy) {
        ROI.copyTo(image); // make copies since args are refs!!
        alpha.copyTo(mask); // make a copie
        x1 = ix;
        y1 = iy;

    }

    classification(Mat *image);
    int copyPercept(classification &unit, Mat &dest);

    Mat image; // percept itself
    Mat mask; // alpha channel
    int x1; // x location of percept in frame
    int y1; // y location of percept in frame

    // Destructor
    ~classification() {
        // Free image and mask
        image.release();
        mask.release();
    }
};

#endif // CLASSIFICATION_H


