#include "ofApp.h"
#include "SubsectionImage.hpp"
#include "TextBlock.hpp"


/**
 * Loads the images and creates the initial state of the Spire
 */
void ofApp::setup()
{
    ofSetFrameRate(60);
    loadImages();
    resetAnimation();
    ofAddListener(animationDone, this, &ofApp::onArtistAnimationComplete);
    
    string artistName = "Kanye West";
    ofColor background(255, 255, 255, 0);
    artistBlock.init(supportingArtist5.width, supportingArtist5.height, artistName, textBackground);
}

/**
 * Updates the App. It's primary purpose is updating the animations of
 * the images that are to be displayed
 */
void ofApp::update(){
    
    /**
     * The render for the first frame tends take a while, ~20-30 
     * seconds, after which it normalizes. This makes sure that
     * updates only happen after that initial render
     */
    if (ofGetFrameNum() > 1) {
        
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
        
        artistBlock.update();
        
        mainArtist1Img.update();
        mainArtist2Img.update();
        
    }
}

/**
 * Draws the screen it draws the background and, if necessary
 * the SubsectionImages
 */
void ofApp::draw(){
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
    defineFadeOut(1000, 30000);
}


/**
 * Draw the Artist Images. This draws each of the SubsectionImages at
 * at the specified location (from the upper-left corner)
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
//    supportingArtist5Img.draw(3130, 10);
    artistBlock.draw(3130, 10);
    supportingArtist6Img.draw(3130, 320);
    
    mainArtist1Img.draw(3590, 10);
    mainArtist2Img.draw(4050, 10);
}


/**
 * Draw the idle animation. This consists of rectangles that hold the 
 * place of images
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


/**
 * This initializes the SubsectionImages. It does so according to the length and
 * width specified in the panels that were defined in the header
 */
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
 * Loads teh default image for each image
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
    
    cout << "define animations\n";
    // LEVEL ONE OF THE SPIRE
    startingArtist11Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 1 + 500);
    startingArtist11Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist11.width, startingArtist11.height), duration, delay * 1 + 500);
    startingArtist11Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 1 + 500, playMusic);
    
    startingArtist12Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 2 + 500);
    startingArtist12Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist12.width, startingArtist12.height), duration, delay * 2 + 500);
    startingArtist12Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 2 + 500);
    
    startingArtist21Img.defineTranslate(ofPoint(200, 0), ofPoint(200, 100), duration * 15, delay * 3 + 500);
    startingArtist21Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist21.width, startingArtist21.height), duration, delay * 3 + 500);
    startingArtist21Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 3 + 500);
    
    startingArtist22Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 4 + 500);
    startingArtist22Img.defineZoom(ofPoint(0, 0), ofPoint(startingArtist22.width, startingArtist22.height), duration, delay * 4 + 500);
    startingArtist22Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 4 + 500);
    
    startingAlbum11Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 5 + 500);
    startingAlbum11Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum11.width, startingAlbum11.height), duration, delay * 5 + 500);
    startingAlbum11Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 5 + 500);
    
    startingAlbum12Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 6 + 500);
    startingAlbum12Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum12.width, startingAlbum12.height), duration, delay * 6 + 500);
    startingAlbum12Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 6 + 500);
    
    startingAlbum21Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 7 + 500);
    startingAlbum21Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum21.width, startingAlbum21.height), duration, delay * 7 + 500);
    startingAlbum21Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 7 + 500);
    
    startingAlbum22Img.defineTranslate(ofPoint(0, 0), ofPoint(0, 100), duration * 15, delay * 8 + 500);
    startingAlbum22Img.defineZoom(ofPoint(0, 0), ofPoint(startingAlbum22.width, startingAlbum22.height), duration, delay * 8 + 500);
    startingAlbum22Img.defineOpacity(ofPoint(0), ofPoint(255), duration * 2, delay * 8 + 500);
    
    
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
//    mainArtist2Img.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 18 + 500);

    // NAME OF THE ARTIST
    artistBlock.defineTranslate(ofPoint(50, supportingArtist5.height / 2), ofPoint(0, supportingArtist5.height / 2), duration, delay * 20 + 500);
    artistBlock.defineOpacity(ofPoint(0), ofPoint(255), duration, delay * 19 + 500);
 
    intervalTime = delay * 50 + 500 + duration;
}


/**
 * Defines the effect where the artists fade out.
 */
void ofApp::defineFadeOut(float duration, float delay) {
    
    cout << "defining fade out\n";
    // FADE IMAGES OUT AT THE END
    startingArtist11Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingArtist12Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingArtist21Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingArtist22Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    
    startingAlbum11Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingAlbum12Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingAlbum21Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    startingAlbum22Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    
    supportingArtist1Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    supportingArtist2Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    supportingArtist3Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    supportingArtist4Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    supportingArtist5Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    supportingArtist6Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    
    mainArtist1Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    mainArtist2Img.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
    
    artistBlock.defineOpacity(ofPoint(255), ofPoint(0), duration, delay);
};


/**
 * This is used to reset the animations. It initializes them to their default state, then
 * defines the animations
 */
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



