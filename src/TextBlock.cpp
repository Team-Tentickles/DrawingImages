//
//  TextBlock.cpp
//  mySketch
//
//  Created by Benjamin Wilcox on 5/6/16.
//
//

#include "TextBlock.hpp"

/**
 * Initialize the TextBlock with a width, a height, and a
 * starting message
 */
void TextBlock::init(float initWidth, float initHeight, string text, ofColor color) {
    width = initWidth;
    height = initHeight;
    textString = text;
    backgroundColor = color;
}


/**
 * Draw the rectangle and the text
 */
void TextBlock::draw(float x, float y) {
    ofSetColor(backgroundColor);
    ofFill();
    ofDrawRectangle(x, y, width, height);
    ofNoFill();
}