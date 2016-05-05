#include "ofApp.h"
#include "SubsectionImage.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    loadImages();
    resetAnimation();
    ofAddListener(animationDone, this, &ofApp::onArtistAnimationComplete);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /**
     * The render for the first frame tends take a while, ~20-30 
     * seconds, after which it normalizes. This makes sure that
     * updates only happen after that initial render
     */
    if (ofGetFrameNum() > 1) {

//        startingArtist11Img.updateTranslate(ofGetLastFrameTime());
//        startingArtist11Img.updateZoom(ofGetLastFrameTime());
//        startingArtist11Img.updateOpacity(ofGetLastFrameTime());
//        
//        startingArtist12Img.updateTranslate(ofGetLastFrameTime());
//        startingArtist12Img.updateZoom(ofGetLastFrameTime());
//        startingArtist12Img.updateOpacity(ofGetLastFrameTime());
//        
//        startingArtist21Img.updateTranslate(ofGetLastFrameTime());
//        startingArtist21Img.updateZoom(ofGetLastFrameTime());
//        
//        startingArtist22Img.updateTranslate(ofGetLastFrameTime());
//        startingArtist22Img.updateZoom(ofGetLastFrameTime());
//        
//        
//        startingAlbum11Img.updateTranslate(ofGetLastFrameTime());
//        startingAlbum11Img.updateZoom(ofGetLastFrameTime());
//        
//        startingAlbum12Img.updateTranslate(ofGetLastFrameTime());
//        startingAlbum12Img.updateZoom(ofGetLastFrameTime());
//        
//        startingAlbum21Img.updateTranslate(ofGetLastFrameTime());
//        startingAlbum21Img.updateZoom(ofGetLastFrameTime());
//        
//        startingAlbum22Img.updateTranslate(ofGetLastFrameTime());
//        startingAlbum22Img.updateZoom(ofGetLastFrameTime());
//        
//        
//        supportingArtist1Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist1Img.updateZoom(ofGetLastFrameTime());
//        
//        supportingArtist2Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist2Img.updateZoom(ofGetLastFrameTime());
//        
//        supportingArtist3Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist3Img.updateZoom(ofGetLastFrameTime());
//        
//        supportingArtist4Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist4Img.updateZoom(ofGetLastFrameTime());
//        
//        supportingArtist5Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist5Img.updateZoom(ofGetLastFrameTime());
//        
//        supportingArtist6Img.updateTranslate(ofGetLastFrameTime());
//        supportingArtist6Img.updateZoom(ofGetLastFrameTime());
//        
//        
//        mainArtist1Img.updateTranslate(ofGetLastFrameTime());
//        mainArtist1Img.updateZoom(ofGetLastFrameTime());
//        
//        mainArtist2Img.updateTranslate(ofGetLastFrameTime());
//        mainArtist2Img.updateZoom(ofGetLastFrameTime());
        
        updateColor(idle1, idle2);
        
        startingArtist11Img.update();
        startingArtist12Img.update();
        startingArtist21Img.update();
        startingArtist22Img.update();
        
        startingAlbum11Img.update();
        startingAlbum12Img.update();
        startingAlbum21Img.update();
        startingAlbum22Img.update();
        
        supportingArtist1Img.update();
        supportingArtist2Img.update();
        supportingArtist3Img.update();
        supportingArtist4Img.update();
        supportingArtist5Img.update();
        supportingArtist6Img.update();
        
        mainArtist1Img.update();
        mainArtist2Img.update();
        
//        curTime += ofGetLastFrameTime() * 1000;
//        if (curTime > intervalTime) {
//            curTime = 0.0;
//            resetAnimation();
//        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cout << "drawing\n";
    drawIdle();
    if (drawArtists) {
        drawArtistImages();
    }
}


/**
 * When the artist animation has completed, this event is
 * called to fade the images out.
 */
void ofApp::onArtistAnimationComplete(string & evtString) {
    cout << "event called: " << evtString << "\n";
    defineFadeOut(1000, 0);
}


/**
 * Draw the Artist Images
 */
void ofApp::drawArtistImages() {
    startingArtist11Img.draw(10, 10);
    startingArtist12Img.draw(420, 10);
    startingArtist21Img.draw(1030, 10);
    startingArtist22Img.draw(1440, 10);
    
    startingAlbum11Img.draw(420, 420);
    startingAlbum12Img.draw(630, 420);
    startingAlbum21Img.draw(1440, 420);
    startingAlbum22Img.draw(1650, 420);
    
    supportingArtist1Img.draw(2050, 10);
    supportingArtist2Img.draw(2510, 10);
    supportingArtist3Img.draw(2050, 320);
    supportingArtist4Img.draw(2820, 10);
    supportingArtist5Img.draw(3130, 10);
    supportingArtist6Img.draw(3130, 320);
    
    mainArtist1Img.draw(3590, 10);
    mainArtist2Img.draw(4050, 10);
}


/**
 * Draw the idle animation
 */
void ofApp::drawIdle() {
    ofSetColor(curColor);
    ofSetBackgroundColor(curColor);
//    ofFill();
    
    ofDrawRectangle(10, 10, startingArtist11.width, startingArtist11.height);
    ofDrawRectangle(420, 10, startingArtist12.width, startingArtist12.height);
    ofDrawRectangle(1030, 10, startingArtist21.width, startingArtist21.height);
    ofDrawRectangle(1440, 10, startingArtist22.width, startingArtist22.height);
    
    ofDrawRectangle(420, 420, startingAlbum11.width, startingAlbum11.height);
    ofDrawRectangle(630, 420, startingAlbum12.width, startingAlbum12.height);
    ofDrawRectangle(1440, 420, startingAlbum21.width, startingAlbum21.height);
    ofDrawRectangle(1650, 420, startingAlbum22.width, startingAlbum22.height);
    
    ofDrawRectangle(2050, 10, supportingArtist1.width, supportingArtist1.height);
    ofDrawRectangle(2510, 10, supportingArtist2.width, supportingArtist2.height);
    ofDrawRectangle(2050, 320, supportingArtist3.width, supportingArtist3.height);
    ofDrawRectangle(2820, 10, supportingArtist4.width, supportingArtist4.height);
    ofDrawRectangle(3130, 10, supportingArtist5.width, supportingArtist5.height);
    ofDrawRectangle(3130, 320, supportingArtist6.width, supportingArtist6.height);
    
    ofDrawRectangle(3590, 10, mainArtist1.width, mainArtist1.height);
    ofDrawRectangle(4050, 10, mainArtist2.width, mainArtist2.height);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


void ofApp::initImages() {
    startingArtist11Img.init(startingArtist11.width, startingArtist11.height, 0, 0);
    startingArtist12Img.init(startingArtist12.width, startingArtist12.height, 0, 0);
    startingArtist21Img.init(startingArtist21.width, startingArtist21.height, 0, 0);
    startingArtist22Img.init(startingArtist22.width, startingArtist22.height, 0, 0);
    
    startingAlbum11Img.init(startingAlbum11.width, startingAlbum11.height, 0, 0);
    startingAlbum12Img.init(startingAlbum12.width, startingAlbum12.height, 0, 0);
    startingAlbum21Img.init(startingAlbum21.width, startingAlbum21.height, 0, 0);
    startingAlbum22Img.init(startingAlbum22.width, startingAlbum22.height, 0, 0);
    
    supportingArtist1Img.init(supportingArtist1.width, supportingArtist1.height, 0, 0);
    supportingArtist2Img.init(supportingArtist2.width, supportingArtist2.height, 0, 0);
    supportingArtist3Img.init(supportingArtist3.width, supportingArtist3.height, 0, 0);
    supportingArtist4Img.init(supportingArtist4.width, supportingArtist4.height, 0, 0);
    supportingArtist5Img.init(supportingArtist5.width, supportingArtist5.height, 0, 0);
    supportingArtist6Img.init(supportingArtist6.width, supportingArtist6.height, 0, 0);
    
    mainArtist1Img.init(mainArtist1.width, mainArtist1.height, 0, 0);
    mainArtist2Img.init(mainArtist1.width, mainArtist2.height, 0, 0);
}


/**
 * Given an array of images, load each of them into the arra
 */
void ofApp::loadImages() {
    string defaultImage = "images/default.jpg";
    
    startingArtist11Img.load(defaultImage);
    startingArtist12Img.load(defaultImage);
    startingArtist21Img.load(defaultImage);
    startingArtist22Img.load(defaultImage);
    
    startingAlbum11Img.load(defaultImage);
    startingAlbum12Img.load(defaultImage);
    startingAlbum21Img.load(defaultImage);
    startingAlbum22Img.load(defaultImage);
    
    supportingArtist1Img.load(defaultImage);
    supportingArtist2Img.load(defaultImage);
    supportingArtist3Img.load(defaultImage);
    supportingArtist4Img.load(defaultImage);
    supportingArtist5Img.load(defaultImage);
    supportingArtist6Img.load(defaultImage);
    
    mainArtist1Img.load(defaultImage);
    mainArtist2Img.load(defaultImage);
}


/**
 * Defines the animations for all of the images on the spire. The user can
 * define the length of the animation for each iamge as well as the delay
 * between each. The animations will be staggered accordingly
 */
void ofApp::defineAnimations(float duration, float delay) {
    
    // LEVEL ONE OF THE SPIRE
    startingArtist11Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 1 + 500);
    startingArtist11Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist11.width, startingArtist11.height), duration, delay * 1 + 500);
    startingArtist11Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 1 + 500);
    
    startingArtist12Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 2 + 500);
    startingArtist12Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist12.width, startingArtist12.height), duration, delay * 2 + 500);
    startingArtist12Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 2 + 500);
    
    startingArtist21Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 3 + 500);
    startingArtist21Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist21.width, startingArtist21.height), duration, delay * 3 + 500);
    startingArtist21Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 3 + 500);
    
    startingArtist22Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 4 + 500);
    startingArtist22Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist22.width, startingArtist22.height), duration, delay * 4 + 500);
    startingArtist22Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 4 + 500);
    
    startingAlbum11Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 5 + 500);
    startingAlbum11Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum11.width, startingAlbum11.height), duration, delay * 5 + 500);
    startingAlbum11Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 5 + 500);
    
    startingAlbum12Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 6 + 500);
    startingAlbum12Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum12.width, startingAlbum12.height), duration, delay * 6 + 500);
    startingAlbum12Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 6 + 500);
    
    startingAlbum21Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 7 + 500);
    startingAlbum21Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum21.width, startingAlbum21.height), duration, delay * 7 + 500);
    startingAlbum21Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 7 + 500);
    
    startingAlbum22Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 8 + 500);
    startingAlbum22Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum22.width, startingAlbum22.height), duration, delay * 8 + 500);
    startingAlbum22Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 8 + 500);
    
    
    // LEVEL TWO OF THE SPIRE
    supportingArtist1Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 10 + 500);
    supportingArtist1Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist1.width, supportingArtist1.height), duration, delay * 10 + 500);
    supportingArtist1Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 10 + 500);
    
    supportingArtist2Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 11 + 500);
    supportingArtist2Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist2.width, supportingArtist2.height), duration, delay * 11 + 500);
    supportingArtist2Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 11 + 500);
    
    supportingArtist3Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 12 + 500);
    supportingArtist3Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist3.width, supportingArtist3.height), duration, delay * 12 + 500);
    supportingArtist3Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 12 + 500);
    
    supportingArtist4Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 13 + 500);
    supportingArtist4Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist4.width, supportingArtist4.height), duration, delay * 13 + 500);
    supportingArtist4Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 13 + 500);
    
    supportingArtist5Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 14 + 500);
    supportingArtist5Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist5.width, supportingArtist5.height), duration, delay * 14 + 500);
    supportingArtist5Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 14 + 500);
    
    supportingArtist6Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 15 + 500);
    supportingArtist6Img.defineZoom(ofPoint(0, 0), ofPoint(supportingArtist6.width, supportingArtist6.height), duration, delay * 15 + 500);
    supportingArtist6Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 15 + 500);
    
    
    // LEVEL THREE OF THE SPIRE
    mainArtist1Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 17 + 500);
    mainArtist1Img.defineZoom(ofPoint(0, 0), ofPoint(mainArtist1.width, mainArtist1.height), duration, delay * 17 + 500);
    mainArtist1Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 17 + 500);
    
    mainArtist2Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 18 + 500);
    mainArtist2Img.defineZoom(ofPoint(0, 0), ofPoint(mainArtist2.width, mainArtist2.height), duration, delay * 18 + 500);
    mainArtist2Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 18 + 500, animationDone);

 
    intervalTime = delay * 50 + 500 + duration;
}


/**
 * Defines the effect where the artists fade out.
 */
void ofApp::defineFadeOut(float duration, float delay) {
    
    cout << "defining fade out\n";
    // FADE IMAGES OUT AT THE END
    startingArtist11Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingArtist12Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingArtist21Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingArtist22Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    
    startingAlbum11Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingAlbum12Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingAlbum21Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    startingAlbum22Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    
    supportingArtist1Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    supportingArtist2Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    supportingArtist3Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    supportingArtist4Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    supportingArtist5Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    supportingArtist6Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    
    mainArtist1Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
    mainArtist2Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay * 50 + 500);
};


void ofApp::resetAnimation() {
    
    // reset to default
    initImages();
    defineAnimations(3000, 1000);
}


/**
 * Update the color of the rectangles
 */
void ofApp::updateColor(ofColor starting, ofColor target) {
    float curPct = abs(sin(ofGetElapsedTimef() / 4));
    curColor = starting.lerp(target, curPct);
}



