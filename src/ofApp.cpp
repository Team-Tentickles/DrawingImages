#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    string im = "images/img";
    string jpg = ".jpg";
    for (int m = 0; m <= 10; m++)
    {
        imageArray[m].load(im + to_string(m) + jpg);
        cout << im + to_string(m) + jpg;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ellapsedTime = ofGetElapsedTimeMillis();
    //cout << ellapsedTime << endl;
    for (int m = 0; m <= 10; m++)
    {
        imageArray[m].draw(500,500);
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
