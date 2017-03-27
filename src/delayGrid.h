#pragma once

#include "ofMain.h"

class delayGrid{

	public:
		void setup();
		void draw();
		void swapBuffers();
		void setCam(ofVideoGrabber* _cam);
		ofTexture getTexture();

private:
		ofVideoGrabber* cam;
		ofFbo *b1, *b2;
		ofShader shiftShader;
};
