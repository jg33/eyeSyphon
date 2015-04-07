#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    eye.setup(640, 480);
    syphon.setName("PS3 Eye");
    video.allocate(640, 480, OF_IMAGE_COLOR);
    video.clear();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    eye.update();
    if(eye.isFrameNew()) video.setFromPixels(eye.getPixels());

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    video.draw(0, 0);
    syphon.publishScreen();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
