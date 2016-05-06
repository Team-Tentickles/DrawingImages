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

class TextBlock : public ofImage {
    
private:
public:
    void init(float width, float height, string text, ofColor color);
    void draw(float x, float y);
    
    string textString;
    ofColor backgroundColor;
};


#endif /* TextBlock_hpp */
