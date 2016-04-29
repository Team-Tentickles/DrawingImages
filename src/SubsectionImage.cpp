//
//  SubsectionImage.cpp
//  mySketch
//
//  Created by Benjamin Wilcox on 4/23/16.
//
//

#include "SubsectionImage.hpp"


/**
 * Initializes the SubsectionImage. The User can specify:
 *      1) the scaled width of the cropped image
 *      2) the scaled height of the cropped image
 *      3) the x position to start cropping at
 *      4) the y position to start cropping at
 */
void SubsectionImage::init(float pcropWidth, float pcropHeight, float cropX, float cropY) {
    cropWidth = pcropWidth;
    cropHeight = pcropHeight;
    
    pos.x = cropX;
    pos.y = cropY;
}

void SubsectionImage::defineTranslate(ofPoint from, ofPoint to, float duration) {
    translateStart = ofGetElapsedTimeMillis();
    translateCur = translateStart;
    translateSpeed = duration;
    translateFrom = from;
    translateTo = to;
}


void SubsectionImage::defineTranslate2(ofPoint from, ofPoint to, float duration, float delay) {
    translateFrom = from;
    translateTo = to;
    translateStart = ofGetElapsedTimef() + (delay / 1000);
    translateCur = ofGetElapsedTimef() + (delay / 1000);
    translateEnd = translateStart + duration;
    translatePercent = 0.0f;
}


void SubsectionImage::updateTranslate() {
    float dist = translateTo.x - pos.x;
    float translateAmount = dist * translateSpeed;
    if (translateAmount > 0.00001) {
        pos.x += translateAmount;
        cout << pos.x;
        cout << "\n";
    }
    
    
}


void SubsectionImage::updateTranslate2(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= translateStart) {
        translateCur += dt * 1000;
        translatePercent = 1 - (translateEnd - translateCur) / (translateEnd - translateStart);
        if (translatePercent < 1.0f) {
            pos = bezierEaseOut(translateFrom, translateTo, translatePercent);
        }
    }
}



void SubsectionImage::update() {
}



void SubsectionImage::draw(float x, float y) {
    ofImage::drawSubsection(x, y, 200, 200, pos.x, pos.y, cropWidth, cropHeight);
}

void SubsectionImage::draw(float x, float y, float w, float h) {
    ofImage::drawSubsection(x, y, w, h, pos.x, pos.y, cropWidth, cropHeight);
}


ofPoint SubsectionImage::linearEase(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    return dist * pct;
}


ofPoint SubsectionImage::bezierEaseOut(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    float mod = pow((pct - 1), 3) + 1;
    cout << mod;
    cout << "\n";
    return dist * mod;
}


