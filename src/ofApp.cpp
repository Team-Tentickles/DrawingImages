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
        for (int m = 0; m < imageArray.size(); m++)
        {
            imageArray[m].updateTranslate2(ofGetLastFrameTime());
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int m = 0; m < imageArray.size(); m++)
    {
        imageArray[m].draw(m * 225, 0);
    }
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
    for (int i = 0; i < imageArray.size(); i++) {
        string loadStr = defaultImage;
        if (i <= (imageURLs.size() - 1)) {
            loadStr = imageURLs[i];
        }
        imageArray[i].load(loadStr);
        imageArray[i].init(200, 200, 0, 0);
        imageArray[i].defineTranslate2(ofPoint(0, 0), ofPoint(60, 0), 5000, 1000);
    }
}
