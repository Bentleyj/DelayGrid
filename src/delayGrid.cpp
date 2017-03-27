#include "delayGrid.h"

//--------------------------------------------------------------
void delayGrid::setup(){
	b1 = new ofFbo();
	b2 = new ofFbo();
	b1->allocate(ofGetWidth(), ofGetHeight());
	b2->allocate(ofGetWidth(), ofGetHeight());

	shiftShader.load("Shaders/shift");
}

void delayGrid::setCam(ofVideoGrabber* _cam) {
	cam = _cam;
}

//--------------------------------------------------------------
void delayGrid::draw(){
	b1->begin();
	shiftShader.begin();
	shiftShader.setUniformTexture("source", b2->getTexture(), 0);
	shiftShader.setUniform2f("cellSize", ofVec2f(cam->getWidth(), cam->getHeight()));
	shiftShader.setUniform2f("bufferSize", ofVec2f(b2->getWidth(), b2->getHeight()));
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shiftShader.end();
	cam->draw(0, 0);
	b1->end();
	b1->draw(0, 0);

	//b2->draw(0, 0);
	//b2->draw(ofGetWidth(), 0);
	swapBuffers();
}

void delayGrid::swapBuffers() {
	ofFbo* tempBuffer;
	tempBuffer = b2;
	b2 = b1;
	b1 = tempBuffer;
}

ofTexture delayGrid::getTexture() {
	return b1->getTexture();
}