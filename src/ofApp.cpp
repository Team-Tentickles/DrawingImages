#include "ofApp.h"
#include "SubsectionImage.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
//    string im = "images/img";
//    string jpg = ".jpg";
//    for (int m = 0; m <= 10; m++)
//    {
//        imageArray[m].load(im + to_string(m) + jpg);
//        cout << im + to_string(m) + jpg;
//    }
    vector<string> v {"images/Kanye.jpg"};
    loadImages(v);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ellapsedTime = ofGetElapsedTimeMillis();
    //cout << ellapsedTime << endl;
    for (int m = 0; m < imageArray.size(); m++)
    {
        imageArray[m].draw(m * 125, 0);
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
//        ofImage temp;
        imageArray[i].load(loadStr);
        
//        imageArray[i].init(temp);
        cout << loadStr;
    }
}
