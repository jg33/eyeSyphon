#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("eyeSyphon");
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    eye.setup(640, 480);
    eye.setAutogain(false);
    //eye.setDesiredFrameRate(30);
    
    
    syphon.setName("PS3 Eye");
    video.allocate(640, 480, OF_IMAGE_COLOR);
    prevFrame.allocate(640, 480, OF_IMAGE_COLOR);
    
    video.clear();
    prevFrame.clear();
    //eye.setGain(255);
    
    
    canvas = new ofxUISuperCanvas("Eye Controls");
    canvas->addSpacer();
    canvas->addSlider("Gain", 0, 61, 32);
    canvas->addSpacer();
    canvas->addSlider("Glitch Threshold", 0, 100, 40);
    ofAddListener(canvas->newGUIEvent,this,&ofApp::guiEvent);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    eye.update();

    if(eye.isFrameNew()){
        if(bIsCatchingGlitches){
            avgDiff =0;
            
            if(prevFrame.getPixels().size()>0){
                
                for(int i =0;i<eye.getPixels().size();i++){
                    avgDiff += abs(eye.getPixels()[i]-prevFrame.getPixels()[i]);

                }
                
                avgDiff /= eye.getPixels().size();
                
            }
            prevFrame = eye.getPixels();
            
        }
        
        if(!bIsCatchingGlitches || avgDiff <= glitchThreshold){
            
            video.setFromPixels(eye.getPixels());

            
        }else if(bIsCatchingGlitches && avgDiff > glitchThreshold) {
            cout<<"caught a glitch on 1! "<< avgDiff<<endl;
            video.setFromPixels(eye.getPixels());

        } else {
            //video.setFromPixels(eye.getPixels());
            
        }
        
    }else{
        //bHasNewFrame = false;
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    video.draw(0, 0);
    syphon.publishScreen();
}

void ofApp::guiEvent(ofxUIEventArgs &e){
    if(e.getName() == "Gain"){
        gain = e.getSlider()->getValue();
        eye.setGain(gain);
    } else if(e.getName() == "Glitch Threshold"){
        glitchThreshold = e.getSlider()->getValue();
        //eye.setGain(gain);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'e':
            canvas->enable();
            break;
            
        case 'd':
            canvas->disable();
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
