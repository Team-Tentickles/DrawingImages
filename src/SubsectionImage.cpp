//
//  SubsectionImage.cpp
//  mySketch
//
//  Created by Benjamin Wilcox on 4/23/16.
//
//

#include "SubsectionImage.hpp"

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

void SubsectionImage::updateTranslate() {
    float dist = translateTo.x - pos.x;
    float translateAmount = dist * translateSpeed;
    if (translateAmount > 0.00001) {
        pos.x += translateAmount;
        cout << pos.x;
        cout << "\n";
    }
    
    
}


void SubsectionImage::update() {
}


void SubsectionImage::draw(float x, float y) {
    ofImage::drawSubsection(x, y, 200, 200, pos.x, pos.y, cropWidth, cropHeight);
}
