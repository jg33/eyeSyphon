#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("eyeSyphon");
    eye.setup(640, 480);
    syphon.setName("PS3 Eye");
    video.allocate(640, 480, OF_IMAGE_COLOR);
    prevFrame.allocate(640, 480, OF_IMAGE_COLOR);

    video.clear();
    prevFrame.clear();
    //eye.setGain(255);
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
        
        if(!bIsCatchingGlitches || avgDiff < glitchThreshold){
            
            video.setFromPixels(eye.getPixels());

            
        }else if(bIsCatchingGlitches && avgDiff > glitchThreshold) {
            cout<<"caught a glitch on 1! "<< avgDiff<<endl;
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
