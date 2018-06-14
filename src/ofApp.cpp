#include "ofApp.h"

using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(640, 480);//カメラセット
    tracker.setup();//Trackerセット
    serial.setup("/dev/cu.usbmodem14141",9600);//シリアルセット
   
}

//--------------------------------------------------------------
void ofApp::update(){//カメラフレームアップデート
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    cam.draw(0, 0);//カメラ表示(位置)
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);//フレームレート表示
    
    if(tracker.getFound()) {
        tracker.draw();
        serial.writeByte('1');
        serial.writeByte('3');
    }else{
        serial.writeByte('2');
        serial.writeByte('4');
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r') {
        tracker.reset();
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
