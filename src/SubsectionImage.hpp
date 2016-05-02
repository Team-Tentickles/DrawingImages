//
//  SubsectionImage.hpp
//  mySketch
//
//  Created by Benjamin Wilcox on 4/23/16.
//
//

#ifndef SubsectionImage_hpp
#define SubsectionImage_hpp

#include <stdio.h>
#include "ofMain.h"

class SubsectionImage : public ofImage {
    
private:
    int curX;
    int curY;
    int cropWidth;
    int cropHeight;
    
    ofPoint pos;
    
    ofPoint translateFrom;
    ofPoint translateTo;
    float translateCur;
    float translateStart;
    float translateEnd;
    float translatePercent;
    float translateSpeed;
    
    ofPoint linearEase(ofPoint from, ofPoint to, float pct);
    ofPoint bezierEaseOut(ofPoint from, ofPoint to, float pct);
    
    ofVideoPlayer *defaultVideo = NULL;
    
public:
    void init(float cropWidth, float cropHeight, float cropX, float cropY);
    void update();
    
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay);
    void updateTranslate(float dt);
    
    void draw(float x, float y);
    void draw(float x, float y, float w, float h);
    void setDefaultVideo(ofVideoPlayer v);
};

#endif /* SubsectionImage_hpp */
