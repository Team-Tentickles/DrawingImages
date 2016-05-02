//
//  animation.h
//  mySketch
//
//  Created by Benjamin Wilcox on 5/1/16.
//
//

#ifndef animation_h
#define animation_h

/**
 * Defines an animation structure. Animations move from one point
 * to another in 2D space. They keep track of the start time, the end
 * time, the current time, and the current percent, as well as the 
 * speed at which it will be played.
 */
struct Animation {
    ofPoint from;
    ofPoint to;
    float current;
    float start;
    float end;
    float percent;
    
};

#endif /* animation_h */
