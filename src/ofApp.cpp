#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    eye.setup(640,480);
    eye.listDevices();
    eye.setUseTexture(false);
    eye.initGrabber(640, 480, true);
    eye.setAutoGainAndShutter(false);
    
    eye.setShutter(0.1);
    syphon.setName("Eye Syphon");
    
    cout<<"format: "<<eye.getPixelFormat()<<endl;
    
    canvas = new ofxUISuperCanvas("Eye Controls");
    canvas->addSpacer();
    canvas->addSlider("Gain", 0, 1, 0.5);
    ofAddListener(canvas->newGUIEvent,this,&ofApp::guiEvent);
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    eye.update();
    
    if(eye.isFrameNew()){
        eye.setLed(true);
    }
    else eye.setLed(false);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofImage pix ;
    //pix.allocate(640, 480, eye.getPixelFormat());
    pix.setFromPixels(eye.getPixelsRef());
    
    pix.draw(0, 0);
    
    syphon.publishScreen();
}


void ofApp::guiEvent(ofxUIEventArgs &e){
    if(e.getName() == "Gain"){
        eye.setGain(e.getSlider()->getValue());
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'c':
            eye.close();
            break;
            
        case 'o':
            eye.initGrabber(640,480);
            break;
        default:
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
