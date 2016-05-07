//
//  TextBlock.hpp
//  mySketch
//
//  Created by Benjamin Wilcox on 5/6/16.
//
//

#ifndef TextBlock_hpp
#define TextBlock_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Animation.h"

class TextBlock : public ofImage {
    
private:
    
    ofTrueTypeFont artistName;
    
    Animation translate;
    Animation zoom;
    Animation opacity;
    
    float zoomWidth;
    float zoomHeight;
    
    float initialWidth;
    float initialHeight;
    
    ofPoint alpha;
    ofPoint pos;
    
    bool opacityComplete;
    vector< ofEvent<string>* > opacityCallback;
    
    bool translateComplete;
    ofEvent<string> translateCallback;
    
    bool zoomComplete;
    vector< ofEvent<string>* > zoomCallback;
    
    string toUpper(string str);
    

    ofPoint bezierEaseOut(ofPoint from, ofPoint to, float pct);
    ofPoint linearEase(ofPoint from, ofPoint to, float pct);
    
public:
    void init(float width, float height, string text, ofColor color);
    void draw(float x, float y);
    void update();
    
    string textString;
    ofColor backgroundColor = {0, 0, 0, 0};
    
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay);
    void defineTranslate(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateTranslate(float dt);
    
    void defineZoom(ofPoint from, ofPoint to, float duration, float delay);
    void defineZoom(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateZoom(float dt);
    
    void defineOpacity(ofPoint from, ofPoint to, float duration, float delay);
    void defineOpacity(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
    void updateOpacity(float dt);
  
    void setArtist(string artistName);
};


#endif /* TextBlock_hpp */
