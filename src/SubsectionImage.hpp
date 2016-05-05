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
#include "Animation.h"

class SubsectionImage : public ofImage {
    
private:
    int curX;
    int curY;
    int cropWidth;
    int cropHeight;
    
    float zoomWidth;
    float zoomHeight;
    
    float initialWidth;
    float initialHeight;
    
    float scaleWidth;
    float scaleHeight;
    
    ofPoint pos;
    ofPoint alpha;
    
    Animation translate;
    Animation zoom;
    Animation opacity;

    ofPoint linearEase(ofPoint from, ofPoint to, float pct);
    ofPoint bezierEaseOut(ofPoint from, ofPoint to, float pct);
    
    bool opacityComplete;
    vector< ofEvent<string>* > opacityCallback;
    
    bool translateComplete;
    ofEvent<string> translateCallback;
    
    bool zoomComplete;
    vector< ofEvent<string>* > zoomCallback;
    
    float getScaleFactor(float from, float to);
    
public:
    void init(float cropWidth, float cropHeight, float cropX, float cropY);
    void load(string imageURL);
    void update();
    
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay);
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateTranslate(float dt);
    
    void defineZoom(ofPoint from, ofPoint to, float duration, float delay);
    void defineZoom(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateZoom(float dt);
    
    void defineOpacity(ofPoint from, ofPoint to, float duration, float delay);
    void defineOpacity(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateOpacity(float dt);
    
    void draw(float x, float y);
    void draw(float x, float y, float w, float h);
};

#endif /* SubsectionImage_hpp */
