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
#include "./AnimatedImage.hpp"

class SubsectionImage : public AnimatedImage {
    
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
    
    void draw(float x, float y);
    void draw(float x, float y, float w, float h);
};

#endif /* SubsectionImage_hpp */
