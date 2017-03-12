#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {

	ofGLFWWindowSettings settings;
	//settings.windowMode = OF_FULLSCREEN;
	settings.windowMode = OF_WINDOW;
	settings.glVersionMajor = 4;
	settings.glVersionMinor = 1;

	ofCreateWindow(settings);

	ofRunApp(new ofApp());

}