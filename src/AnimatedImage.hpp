//
//  AnimatedImage.hpp
//  mySketch
//
//  Created by Benjamin Wilcox on 5/6/16.
//
//

#ifndef AnimatedImage_hpp
#define AnimatedImage_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Animation.h"

class AnimatedImage : public ofImage {
    
    private:
   
        Animation translate;
        Animation zoom;
        Animation opacity;
    
        bool translateComplete;
        bool zoomComplete;
        bool opacityComplete;
    
        ofPoint linearEase(ofPoint from, ofPoint to, float pct);
        ofPoint bezierEaseOut(ofPoint from, ofPoint to, float pct);
    
    public:
    
        void defineTranslate(ofPoint from, ofPoint to, float duration, float delay);
        void defineTranslate(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
        void updateTranslate(float dt);
        
        void defineZoom(ofPoint from, ofPoint to, float duration, float delay);
        void defineZoom(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
        void updateZoom(float dt);
        
        void defineOpacity(ofPoint from, ofPoint to, float duration, float delay);
        void defineOpacity(ofPoint from, ofPoint to, float duration, float delay, ofEvent<string> & onComplete);
        void updateOpacity(float dt);
    
    
};

#endif /* AnimatedImage_hpp */
