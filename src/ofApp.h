#pragma once

#include "ofMain.h"
#include "SubsectionImage.hpp"
#include "Panel.hpp"
#include "TextBlock.hpp"


class ofApp : public ofBaseApp{

    private:
    
        // Dimensions for the starting artist
        Panel startingArtist11 = {400.0, 600.0};
        Panel startingArtist12 = {600.0, 400.0};
        Panel startingArtist21 = {400.0, 600.0};
        Panel startingArtist22 = {600.0, 400.0};
        Panel startingAlbum11 = {200.0, 200.0};
        Panel startingAlbum12 = {200.0, 200.0};
        Panel startingAlbum21 = {200.0, 200.0};
        Panel startingAlbum22 = {200.0, 200.0};
    
        Panel supportingArtist1 = {450, 300};
        Panel supportingArtist2 = {300, 450};
        Panel supportingArtist3 = {450, 300};
        Panel supportingArtist4 = {300, 450};
        Panel supportingArtist5 = {450, 300};
        Panel supportingArtist6 = {300, 450};
    
        Panel mainArtist1 = {450, 450};
        Panel mainArtist2 = {450, 450};
    
        float colorPct = 0.0;
        ofColor idle1 = {141,82,224};
        ofColor idle2 = {247,24,108};
        ofColor textBackground = {0, 0, 0};
        ofColor curColor = idle1;
    
        float curTime = 0.0;
        float intervalTime = 30000.0;
    
        bool drawArtists = true;
        void drawArtistImages();
        void drawIdle();
    
        ofEvent<string> dataReceived;
    
        void onArtistAnimationComplete(string & evtString);
    
        void defineFadeOut(float duration, float delay);
        void updateColor(ofColor starting, ofColor target);
    
	public:
    
        //---for the images
        array<SubsectionImage, 18> imageArray;
    
        SubsectionImage startingArtist11Img;
        SubsectionImage startingArtist12Img;
        SubsectionImage startingArtist21Img;
        SubsectionImage startingArtist22Img;
        SubsectionImage startingAlbum11Img;
        SubsectionImage startingAlbum12Img;
        SubsectionImage startingAlbum21Img;
        SubsectionImage startingAlbum22Img;
        
        SubsectionImage supportingArtist1Img;
        SubsectionImage supportingArtist2Img;
        SubsectionImage supportingArtist3Img;
        SubsectionImage supportingArtist4Img;
        SubsectionImage supportingArtist5Img;
        SubsectionImage supportingArtist6Img;
        
        SubsectionImage mainArtist1Img;
        SubsectionImage mainArtist2Img;
    
        TextBlock artistBlock;
    
        string mainArtistName;
    
        //---for the timer
        float ellapsedTime;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void loadImages();
        void initImages();
        void defineAnimations(float duration, float delay);
    
        void setupFadeZoomAnimation(SubsectionImage img);
    
        void resetAnimation();
        ofEvent<string> animationDone;
        ofEvent<string> playMusic;
};
