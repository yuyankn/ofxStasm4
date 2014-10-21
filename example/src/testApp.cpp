#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	stasm.setup();
	
	const int camWidth = 640, camHeight = 480;
	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(30);
	vidGrabber.initGrabber(camWidth,camHeight);

	frame.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.update();
	
	if (vidGrabber.isFrameNew()){
		
		frame.setFromPixels(vidGrabber.getPixels(), frame.width, frame.height, OF_IMAGE_COLOR);
		frame.update();
		
		stasm.setImage(frame);
		stasm.update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	stasm.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}