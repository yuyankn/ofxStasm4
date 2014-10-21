#include "ofxStasm4.h"

ofxStasm4::ofxStasm4() {

}

ofxStasm4::~ofxStasm4() {

}

void ofxStasm4::setup() {

}

void ofxStasm4::setImage(ofImage& img) {
	viewImg.clone(img);
	srcImg = ofxCv::toCv(viewImg);
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
}

void ofxStasm4::update() {
	int foundface;
	float fLandmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)

    char xmlPath[256];
    sprintf(xmlPath, "%s../../../../../addons/ofxStasm4/libs/data/",
            ofToDataPath("").c_str());
	if (!stasm_search_single(&foundface, fLandmarks,
							 (const char*)srcImg.data, srcImg.cols, srcImg.rows, "",
                              xmlPath))
	{
		printf("Error in stasm_search_single: %s\n", stasm_lasterr());
		return;
	}

	if(foundface) {
		// draw the landmarks on the image as white dots (image is monochrome)
		stasm_force_points_into_image(fLandmarks, srcImg.cols, srcImg.rows);
		for(int i = 0; i < stasm_NLANDMARKS; i++) {
			landmarks[i] = ofVec2f(fLandmarks[2*i], fLandmarks[2*i+1]);
		}
	}
}

void ofxStasm4::draw(float x, float y) {
	viewImg.draw(x, y);
	ofSetColor(0, 255, 0);
	for(int i = 0; i < stasm_NLANDMARKS; i++)
		ofCircle(landmarks[i].x + x, landmarks[i].y + y, 1);
	ofSetColor(255);
}