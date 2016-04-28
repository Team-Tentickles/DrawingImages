#include "ofApp.h"
#include "SubsectionImage.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    vector<string> v {"images/Kanye.jpg"};
    loadImages(v);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /**
     * The render for the first frame tends take a while, ~20-30 
     * seconds, after which it normalizes. This makes sure that
     * updates only happen after that initial render
     */
    if (ofGetFrameNum() > 1) {
//        for (int m = 0; m < imageArray.size(); m++)
//        {
//            imageArray[m].updateTranslate2(ofGetLastFrameTime());
//        }
        startingArtist11Img.updateTranslate2(ofGetLastFrameTime());
        startingArtist12Img.updateTranslate2(ofGetLastFrameTime());
        startingArtist21Img.updateTranslate2(ofGetLastFrameTime());
        startingArtist22Img.updateTranslate2(ofGetLastFrameTime());
        
        startingAlbum11Img.updateTranslate2(ofGetLastFrameTime());
        startingAlbum12Img.updateTranslate2(ofGetLastFrameTime());
        startingAlbum21Img.updateTranslate2(ofGetLastFrameTime());
        startingAlbum22Img.updateTranslate2(ofGetLastFrameTime());
        
        supportingArtist1Img.updateTranslate2(ofGetLastFrameTime());
        supportingArtist2Img.updateTranslate2(ofGetLastFrameTime());
        supportingArtist3Img.updateTranslate2(ofGetLastFrameTime());
        supportingArtist4Img.updateTranslate2(ofGetLastFrameTime());
        supportingArtist5Img.updateTranslate2(ofGetLastFrameTime());
        supportingArtist6Img.updateTranslate2(ofGetLastFrameTime());
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    for (int m = 0; m < imageArray.size(); m++)
//    {
//        imageArray[m].draw(m * 225, 0);
//    }
    startingArtist11Img.draw(10, 10, startingArtist11.width, startingArtist11.height);
    startingArtist12Img.draw(420, 10, startingArtist12.width, startingArtist12.height);
    startingArtist21Img.draw(1030, 10, startingArtist21.width, startingArtist21.height);
    startingArtist22Img.draw(1440, 10, startingArtist22.width, startingArtist22.height);
    
    startingAlbum11Img.draw(420, 420, startingAlbum11.width, startingAlbum11.height);
    startingAlbum12Img.draw(630, 420, startingAlbum12.width, startingAlbum12.height);
    startingAlbum21Img.draw(1440, 420, startingAlbum21.width, startingAlbum21.height);
    startingAlbum22Img.draw(1650, 420, startingAlbum22.width, startingAlbum22.height);
    
    supportingArtist1Img.draw(2050, 10, supportingArtist1.width, supportingArtist1.height);
    supportingArtist2Img.draw(2510, 10, supportingArtist2.width, supportingArtist2.height);
    supportingArtist3Img.draw(2050, 320, supportingArtist3.width, supportingArtist3.height);
    supportingArtist4Img.draw(2820, 10, supportingArtist4.width, supportingArtist4.height);
    supportingArtist5Img.draw(3130, 10, supportingArtist5.width, supportingArtist5.height);
    supportingArtist6Img.draw(3130, 320, supportingArtist6.width, supportingArtist6.height);
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
 * Given an array of images, load each of them into the arra
 */
void ofApp::loadImages(vector<string> imageURLs) {
    string defaultImage = "images/Kanye.jpg";
//    for (int i = 0; i < imageArray.size(); i++) {
//        string loadStr = defaultImage;
//        if (i <= (imageURLs.size() - 1)) {
//            loadStr = imageURLs[i];
//        }
//        imageArray[i].load(loadStr);
//        imageArray[i].init(200, 200, 0, 0);
//        imageArray[i].defineTranslate2(ofPoint(0, 0), ofPoint(60, 0), 5000, 1000);
//    }
    startingArtist11Img.load(defaultImage);
    startingArtist11Img.init(200, 200, 0, 0);
    startingArtist11Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    startingArtist12Img.load(defaultImage);
    startingArtist12Img.init(200, 200, 0, 0);
    startingArtist12Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 10), 2000, 2500);
    
    startingArtist21Img.load(defaultImage);
    startingArtist21Img.init(200, 200, 0, 0);
    startingArtist21Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 10), 2000, 3500);
    
    startingArtist22Img.load(defaultImage);
    startingArtist22Img.init(200, 200, 0, 0);
    startingArtist22Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 10), 2000, 4500);
    
    startingAlbum11Img.load(defaultImage);
    startingAlbum11Img.init(200, 200, 0, 0);
    startingAlbum11Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 5500);
    
    startingAlbum12Img.load(defaultImage);
    startingAlbum12Img.init(200, 200, 0, 0);
    startingArtist12Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 6500);
    
    startingAlbum21Img.load(defaultImage);
    startingArtist21Img.init(200, 200, 0, 0);
    startingArtist21Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 7500);
    
    startingAlbum22Img.load(defaultImage);
    startingArtist22Img.init(200, 200, 0, 0);
    startingArtist22Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 8500);
    
    supportingArtist1Img.load(defaultImage);
    supportingArtist1Img.init(200, 200, 0, 0);
    supportingArtist1Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    supportingArtist2Img.load(defaultImage);
    supportingArtist2Img.init(200, 200, 0, 0);
    supportingArtist2Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    supportingArtist3Img.load(defaultImage);
    supportingArtist3Img.init(200, 200, 0, 0);
    supportingArtist3Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    supportingArtist4Img.load(defaultImage);
    supportingArtist4Img.init(200, 200, 0, 0);
    supportingArtist4Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    supportingArtist5Img.load(defaultImage);
    supportingArtist5Img.init(200, 200, 0, 0);
    supportingArtist5Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
    supportingArtist6Img.load(defaultImage);
    supportingArtist6Img.init(200, 200, 0, 0);
    supportingArtist6Img.defineTranslate2(ofPoint(0, 0), ofPoint(100, 100), 2000, 1500);
    
}
