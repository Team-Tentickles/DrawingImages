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
#include "Animation.h";

class SubsectionImage : public ofImage {
    
private:
    int curX;
    int curY;
    int cropWidth;
    int cropHeight;
    
    float maxWidth;
    float maxHeight;
    
    ofPoint pos;
    ofPoint alpha;
    
    Animation translate;
    Animation zoom;
    Animation opacity;

    ofPoint linearEase(ofPoint from, ofPoint to, float pct);
    ofPoint bezierEaseOut(ofPoint from, ofPoint to, float pct);
    
public:
    void init(float cropWidth, float cropHeight, float cropX, float cropY);
    void update();
    
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay);
    void updateTranslate(float dt);
    
    void defineZoom(ofPoint from, ofPoint to, float duration, float delay);
    void updateZoom(float dt);
    
    void defineOpacity(ofPoint from, ofPoint to, float duration, float delay);
    void updateOpacity(float dt);
    
    void draw(float x, float y);
    void draw(float x, float y, float w, float h);
};

#endif /* SubsectionImage_hpp */
