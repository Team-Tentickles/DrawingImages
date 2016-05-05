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
    
    float initWidth = width;
    float initHeight = height;
    
    width = 0;
    height = 0;
    
    bool wider = initWidth > pcropWidth;
    bool taller = initHeight > pcropHeight;
    if (wider && taller) {
        
    }
    maxWidth = 0.0;
    maxHeight = 0.0;
    
    alpha.x = 255;
    pos.x = cropX;
    pos.y = cropY;
}


/**
 * Define a translation animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void SubsectionImage::defineTranslate(ofPoint from, ofPoint to, float duration, float delay) {
    translate.from = from;
    translate.to = to;
    translate.start = ofGetElapsedTimef() + (delay / 1000);
    translate.current = ofGetElapsedTimef() + (delay / 1000);
    translate.end = translate.start + duration;
    translate.percent = 0.0f;
}


/**
 * Define a zoom animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void SubsectionImage::defineZoom(ofPoint from, ofPoint to, float duration, float delay) {
    zoom.from = from;
    zoom.to = to;
    zoom.start = ofGetElapsedTimef() + (delay / 1000);
    zoom.current = ofGetElapsedTimef() + (delay / 1000);
    zoom.end = translate.start + duration;
    zoom.percent = 0.0f;
}


/**
 * Define an opacity animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void SubsectionImage::defineOpacity(ofPoint from, ofPoint to, float duration, float delay) {
    opacity.from = from;
    opacity.to = to;
    opacity.start = ofGetElapsedTimef() + (delay / 1000);
    opacity.current = ofGetElapsedTimef() + (delay / 1000);
    opacity.end = translate.start + duration;
    opacity.percent = 0.0f;
}


/**
 * updates an ongoing translate animation. It adds an amount to the position of the 
 * image based on an the change in time and the specified duration
 */
void SubsectionImage::updateTranslate(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= translate.start) {
        translate.current += dt * 1000;
        translate.percent = 1 - (translate.end - translate.current) / (translate.end - translate.start);
        if (translate.percent < 1.0f) {
            pos = bezierEaseOut(translate.from, translate.to, translate.percent);
        }
    }
}


/**
 * updates an ongoing zoom animation. It increases the width and height of the
 * image based on an the change in time and the specified duration
 */
void SubsectionImage::updateZoom(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= zoom.start) {
        zoom.current += dt * 1000;
        zoom.percent = 1 - (zoom.end - zoom.current) / (zoom.end - zoom.start);
        if (zoom.percent < 1.0f) {
            ofPoint dim = bezierEaseOut(zoom.from, zoom.to, zoom.percent);
            width = dim.x;
            height = dim.y;
        }
    }
}

/**
 * updates an ongoing opacity animation. It modifies the opacity of the image
 * based on the change in time and the specified duration.
 */
void SubsectionImage::updateOpacity(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= opacity.start) {
        opacity.current += dt * 1000;
        opacity.percent = 1 - (opacity.end - opacity.current) / (opacity.end - opacity.start);
        if (opacity.percent < 1.0f) {
            alpha = bezierEaseOut(opacity.from, opacity.to, opacity.percent);
        }
    }
}


/**
 * Update all animations
 */
void SubsectionImage::update() {
    updateTranslate(ofGetLastFrameTime());
    updateOpacity(ofGetLastFrameTime());
    updateZoom(ofGetLastFrameTime());
}


/**
 * Draws a subsection of the image at the specified x and y coordinates on the window,
 * with the specified width and height and at the current crop position of the plot.
 */
void SubsectionImage::draw(float x, float y) {
    ofEnableAlphaBlending();
    ofSetColor(ofColor(255, 255, 255, alpha.x));
    ofImage::drawSubsection(x, y, width, height, pos.x, pos.y, cropWidth, cropHeight);
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
 * A function which increments from one point to another based on the specified percent.
 * The amount incremented is constant throughout the execution time.
 */
ofPoint SubsectionImage::linearEase(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    return dist * pct;
}


/**
 * A function which increments from one point to another based on the specified percent.
 * The amount incremented is large at first, but gets smaller the further along in the
 * animation it is.
 */
ofPoint SubsectionImage::bezierEaseOut(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    float mod = pow((pct - 1), 3) + 1;
    return dist * mod;
}


