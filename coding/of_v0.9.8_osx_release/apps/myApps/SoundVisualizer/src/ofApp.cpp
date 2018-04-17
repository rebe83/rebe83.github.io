#include "ofApp.h"

//based off of https://www.youtube.com/watch?v=IiTsE7P-GDs
//piano.mp3 sampled from https://www.youtube.com/watch?v=Z7NGW6J0vz8
//--------------------------------------------------------------
void ofApp::setup(){
    music.loadSound("piano.mp3");
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
    //the number of frequency zones acknowledged
    bands = 1000;
    
    music.setLoop(true);
    music.setVolume(0.3);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    float *value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.8f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < bands; i++) {
        ofSetColor((10*i%255),0 + (i*64%255), (20*i%255));
        if (ofGetWindowWidth() > bands) {
        ofDrawRectangle((float) 5*i*(ofGetWindowWidth()/bands), ofGetWindowHeight(), (float) 5*(ofGetWindowWidth()/bands), -fftSmooth[i]*1000);
        }
        else {
            ofDrawRectangle(5*i, ofGetWindowHeight(), 5, -fftSmooth[i]*1000);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case '1':
            music.play();
            break;
        case '2':
            music.stop();
            break;
    }
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
