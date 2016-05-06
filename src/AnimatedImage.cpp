//
//  AnimatedImage.cpp
//  mySketch
//
//  Created by Benjamin Wilcox on 5/6/16.
//
//

#include "AnimatedImage.hpp"

/**
 * Define a translation animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void AnimatedImage::defineTranslate(ofPoint from, ofPoint to, float duration, float delay) {
    translate.from = from;
    
    // make sure the translate doesn't extend outside the bounds of the image
    if ((to.y - from.y) + cropHeight > height) {
        to.y = height + from.y - cropHeight;
    } else if (to.y - from.y < 0) {
        to.y = 0;
    }
    
    if ((to.x - from.x) + cropWidth > width) {
        to.x = width + from.x - cropWidth;
    } else if (to.x - from.x < 0) {
        to.x = 0;
    }
    
    translate.to = to;
    translate.start = ofGetElapsedTimef() + (delay / 1000);
    translate.current = ofGetElapsedTimef() + (delay / 1000);
    translate.end = translate.start + duration;
    translate.percent = 0.0f;
    translateComplete = false;
}

/**
 * Define a translation animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously. This
 * variation registers a function that will be called on completion
 */
void AnimatedImage::defineTranslate(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete) {
    translateCallback = onComplete;
    defineTranslate(from, to, duration, delay);
}

/**
 * Define a zoom animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void AnimatedImage::defineZoom(ofPoint from, ofPoint to, float duration, float delay) {
    zoom.from = from;
    zoom.to = to;
    zoom.start = ofGetElapsedTimef() + (delay / 1000);
    zoom.current = ofGetElapsedTimef() + (delay / 1000);
    zoom.end = translate.start + duration;
    zoom.percent = 0.0f;
    zoomComplete = false;
}


/**
 * Define an opacity animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously. This
 * variation registers a function that will be called on completion
 */
void AnimatedImage::defineOpacity(ofPoint from, ofPoint to, float duration, float delay) {
    opacity.from = from;
    opacity.to = to;
    opacity.start = ofGetElapsedTimef() + (delay / 1000);
    opacity.current = ofGetElapsedTimef() + (delay / 1000);
    opacity.end = translate.start + duration;
    opacity.percent = 0.0f;
    opacityComplete = false;
}


/**
 * Define an opacity animation. The User enters in the point they want to start the
 * animation at, then enters the point they want to ove to. They specify how long they
 * want the animation to last, and can enter a delay that says how long they want to
 * wait before that animation is executed (0 would mean it starts instantaneously.
 */
void AnimatedImage::defineOpacity(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete) {
    opacityCallback.push_back(&onComplete);
    defineOpacity(from, to, duration, delay);
}


/**
 * updates an ongoing translate animation. It adds an amount to the position of the
 * image based on an the change in time and the specified duration
 */
void AnimatedImage::updateTranslate(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= translate.start) {
        translate.current += dt * 1000;
        translate.percent = 1 - (translate.end - translate.current) / (translate.end - translate.start);
        if (translate.percent < 1.0f) {
            pos = bezierEaseOut(translate.from, translate.to, translate.percent);
        }
        //        else {
        ////            if (!translateComplete) {
        ////                translateComplete = true;
        ////                string msg = "animation complete";
        ////                ofNotifyEvent(translateCallback, msg, this);
        //            }
        //        }
    }
}


/**
 * updates an ongoing zoom animation. It increases the width and height of the
 * image based on an the change in time and the specified duration
 */
void AnimatedImage::updateZoom(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= zoom.start) {
        zoom.current += dt * 1000;
        zoom.percent = 1 - (zoom.end - zoom.current) / (zoom.end - zoom.start);
        if (zoom.percent < 1.0f) {
            ofPoint dim = bezierEaseOut(zoom.from, zoom.to, zoom.percent);
            zoomWidth = dim.x;
            zoomHeight = dim.y;
        } else {
            if (!zoomComplete) {
                zoomComplete = true;
                string msg = "animation complete";
                for (int i = 0; i < zoomCallback.size(); i++) {
                    cout << msg;
                    ofNotifyEvent(*zoomCallback[i], msg, this);
                }
                zoomCallback.clear();
            }
        }
    }
}

/**
 * updates an ongoing opacity animation. It modifies the opacity of the image
 * based on the change in time and the specified duration.
 */
void AnimatedImage::updateOpacity(float dt) {
    // convert the current time to a percent of completion
    if (ofGetElapsedTimef() >= opacity.start) {
        opacity.current += dt * 1000;
        opacity.percent = 1 - (opacity.end - opacity.current) / (opacity.end - opacity.start);
        if (opacity.percent < 1.0f) {
            alpha = bezierEaseOut(opacity.from, opacity.to, opacity.percent);
        } else {
            if (!opacityComplete) {
                cout << opacityComplete << "\n";
                opacityComplete = true;
                string msg = "opacity complete";
                for (int i = 0; i < opacityCallback.size(); i++) {
                    //                    cout << msg;
                    ofNotifyEvent(*opacityCallback[i], msg, this);
                }
                opacityCallback.clear();
            }
        }
    }
}


/**
 * Update all animations
 */
void AnimatedImage::update() {
    updateTranslate(ofGetLastFrameTime());
    updateOpacity(ofGetLastFrameTime());
    updateZoom(ofGetLastFrameTime());
}


/**
 * A function which increments from one point to another based on the specified percent.
 * The amount incremented is constant throughout the execution time.
 */
ofPoint AnimatedImage::linearEase(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    return dist * pct;
}


/**
 * A function which increments from one point to another based on the specified percent.
 * The amount incremented is large at first, but gets smaller the further along in the
 * animation it is.
 */
ofPoint AnimatedImage::bezierEaseOut(ofPoint from, ofPoint to, float pct) {
    ofPoint dist = to - from;
    float mod = pow((pct - 1), 3) + 1;
    return dist * mod;
}