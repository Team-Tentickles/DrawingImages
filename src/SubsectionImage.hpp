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
    float translateSpeed;
    
public:
    void init(float cropWidth, float cropHeight, float cropX, float cropY);
    void update();
    
    void defineTranslate(ofPoint from, ofPoint to, float duration);
    void updateTranslate();
    
    void draw(float x, float y);
};

#endif /* SubsectionImage_hpp */
