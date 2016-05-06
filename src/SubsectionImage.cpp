//
//  SubsectionImage.cpp
//  mySketch
//
//  Created by Benjamin Wilcox on 4/23/16.
//
//

#include "SubsectionImage.hpp"


/**
 * Load an image from the URL
 */
void SubsectionImage::load(string imageURL) {
    ofImage::load(imageURL);
    initialWidth = width;
    initialHeight = height;
}


/**
 * Initializes the SubsectionImage. The User can specify:
 *      1) the scaled width of the cropped image
 *      2) the scaled height of the cropped image
 *      3) the x position to start cropping at
 *      4) the y position to start cropping at
 */
void SubsectionImage::init(float sectionWidth, float sectionHeight, float cropX, float cropY) {
    cropWidth = sectionWidth;
    cropHeight = sectionHeight;
    
    float actualWidth = initialWidth;
    float actualHeight = initialHeight;
    
    zoomWidth = 0;
    zoomHeight = 0;
    
    bool wider = actualWidth > sectionWidth;
    bool taller = actualHeight > sectionHeight;
    
    if (wider && taller) {
        cout << "wider and taller\t";
        // choose the scale factor that will best fit the image to the display
        if (getScaleFactor(sectionWidth, actualWidth) < getScaleFactor(sectionHeight, actualHeight)) {
            cout << "wider\n";
            scaleWidth = actualWidth * getScaleFactor(sectionHeight, actualHeight) * 1.25;
            scaleHeight = actualHeight * getScaleFactor(sectionHeight, actualHeight) * 1.25;
            resize(scaleWidth, scaleHeight);
        } else {
            cout << "taller\n";
            scaleWidth = actualWidth * getScaleFactor(sectionWidth, actualWidth) * 1.25;
            scaleHeight = actualHeight * getScaleFactor(sectionWidth, actualWidth) * 1.25;
            resize(scaleWidth, scaleHeight);
        }
    }
    else if (wider) {
        cout << "wider\n";
        scaleWidth = actualWidth * getScaleFactor(sectionHeight, actualHeight) * 1.25;
        scaleHeight = actualHeight * getScaleFactor(sectionHeight, actualHeight) * 1.25;
        resize(scaleWidth, scaleHeight);
    }
    else if (taller) {
        cout << "taller\n";
        scaleWidth = actualWidth * getScaleFactor(sectionWidth, actualWidth) * 1.25;
        scaleHeight = actualHeight * getScaleFactor(sectionWidth, actualWidth) * 1.25;
        resize(scaleWidth, scaleHeight);
    } else {
        cout << "thinner and shorter\t";
        if (getScaleFactor(sectionWidth, actualWidth) < getScaleFactor(sectionHeight, actualHeight)) {
            cout << "thinner\n";
            scaleWidth = actualWidth * getScaleFactor(sectionHeight, actualHeight) * 1.25;
            scaleHeight = actualHeight * getScaleFactor(sectionHeight, actualHeight) * 1.25;
            resize(scaleWidth, scaleHeight);
        } else {
            cout << "shorter\n";
            scaleWidth = actualWidth * getScaleFactor(sectionWidth, actualWidth) * 1.25;
            scaleHeight = actualHeight * getScaleFactor(sectionWidth, actualWidth) * 1.25;
            resize(scaleWidth, scaleHeight);
        }
    }

    
//    maxWidth = 0.0;
//    maxHeight = 0.0;
    
    alpha.x = 255;
    pos.x = cropX;
    pos.y = cropY;
}




/**
 * Draws a subsection of the image at the specified x and y coordinates on the window,
 * with the specified width and height and at the current crop position of the plot.
 */
void SubsectionImage::draw(float x, float y) {
    ofEnableAlphaBlending();
    ofSetColor(ofColor(255, 255, 255, alpha.x));
    ofImage::drawSubsection(x, y, zoomWidth, zoomHeight, pos.x, pos.y, cropWidth, cropHeight);
    ofDisableAlphaBlending();
}


/**
 * Draws a subsection of the image at the specified x and y coordinates on the window,
 * and at the current crop position of the plot.
 */
void SubsectionImage::draw(float x, float y, float w, float h) {
    ofImage::drawSubsection(x, y, w, h, pos.x, pos.y, cropWidth, cropHeight);
}


/**
 * determine the scale factor between two points. 
 */
float SubsectionImage::getScaleFactor(float from, float to) {
    if (to == 0) {
        return 0;
    }
    return from / to;
}


