#pragma once
#include "stasm_lib.h"
#include "ofxCv.h"

class ofxStasm4 {
	cv::Mat srcImg;
	ofImage viewImg;
	ofVec2f landmarks[stasm_NLANDMARKS];
public:
	ofxStasm4();
	~ofxStasm4();
	void setup();
	void setImage(ofImage& img);
	void update();
	void draw(float x, float y);
	void copyToLandmarks(ofVec2f& points);
};