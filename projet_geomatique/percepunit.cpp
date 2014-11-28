#include <percepunit.h>

percepunit::percepunit(Mat *src)
{
    Mat orig, meanshift, mask, flood, reconstruction, Matrice;
    vector<percepunit> percepunits;                 // dynamic vector to store instances of percepunit.

    image = *src;

    /// Copy the original image for in-place processing.
    image.copyTo(orig);
    image.copyTo(Matrice);

    // morphology (supports in place operation)
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5,5), Point(2, 2) );
    morphologyEx(image, image, MORPH_CLOSE, element);
    morphologyEx(image, image, MORPH_OPEN, element);

    // Mean shift filtering
    pyrMeanShiftFiltering(image, meanshift, 10, 35, 3);

    RNG rng = theRNG();

    // place to store ffill masks
    mask = Mat( meanshift.rows+2, meanshift.cols+2, CV_8UC1, Scalar::all(0) ); // Make black single-channel image.
    meanshift.copyTo(flood); // copy image
    int area;
    Rect *boundingRect = new Rect(); // Stored bounding box for each flooded area.

    // Loop through all the pixels and flood fill.
    for( int y = 0; y < meanshift.rows; y++ )
    {
        for( int x = 0; x < meanshift.cols; x++ )
        {
            if( mask.at<uchar>(y+1, x+1) == 0 ) // mask is offset from original image.
            {
                Scalar newVal( rng(256), rng(256), rng(256) );

                area = floodFill( flood, mask, Point(x,y), newVal, boundingRect, Scalar::all(1), Scalar::all(1), 8|255<<8);
                //Extract a subimage for each flood, if the flood is large enough.
                if (boundingRect->width >35 && boundingRect->height >35) {

                    Mat ROI = orig(*boundingRect); // Make a cropped reference (not copy) of the image

                    // crop translated mask to register with original image.
                    boundingRect->y++;
                    boundingRect->height++;
                    boundingRect->x++;
                    boundingRect->width++;
                    Mat alpha = mask(*boundingRect);

                    // Append an instance to the vector.
                    percepunits.push_back(percepunit(ROI, alpha, boundingRect->x-1, boundingRect->y-1, boundingRect->width-1, boundingRect->height-1));
                }

            }
        }
    }

    // New Image for reconstruction
    reconstruction = Mat(mask.rows,mask.cols,CV_8UC3, Scalar(0,0,0)); // red background

    /// Loop through instances and print
    for(int i = 0; i <percepunits.size(); i++) {

        // Copy percept into reconstruction.
        copyPercept(percepunits[i], reconstruction);

    }

    for (int row = 0 ; row < Matrice.rows ; row++ )
    {
        for (int col = 0 ; col  < Matrice.cols ; col++ )
        {
            Matrice.at<uchar>(row,col) = reconstruction.at<uchar>(row,col);
        }
    }
    *src = Matrice;

    /// Destructor free memory
    orig.release();
    meanshift.release();
    mask.release();
    flood.release();
    reconstruction.release();
    Matrice.release();

}

/// pixel by pixel offset copy of perceptUnit into larger image.
int percepunit::copyPercept(percepunit &unit, Mat &dest) {

    // Loop through pixels in percept image
    for( int y = 0; y < unit.image.rows; y++ ) {
        for( int x = 0; x < unit.image.cols; x++ ) {
            // Make sure this pixel is in the mask.
            if (unit.mask.at<char>(y,x) != 0) {
                // get pixels from src image:
                Vec3b pixel = unit.image.at<Vec3b>(y,x); // Vec3b is a 3 element vector of unsigned chars.

                // set pixels in dest image (offset for this percept)
                dest.at<Vec3b>(y+unit.y1,x+unit.x1) = pixel;
            }
        }
    }


}
