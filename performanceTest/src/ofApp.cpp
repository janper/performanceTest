#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetBackgroundColor(0, 0, 0);
	shader.load("shaders\\shader");

	const float side = 4.0;
	const vector<float> vertices{
		side,  side, 0.0f,
		-side,  side, 0.0f,
		side, -side, 0.0f,
		-side, -side, 0.0f
	};

	const vector<ofIndexType> indices{ 0, 1, 2, 1, 2, 3 };

	const int count = 10000;
	for (int i = 0; i < count; ++i) {
		ofVec2f pos{ ofRandom(ofGetWidth()), ofRandom(ofGetHeight()) };

		shared_ptr<ofVboMesh> mesh = make_shared<ofVboMesh>();

		for (int j = 0; j < vertices.size(); j += 3) {
			ofVec3f vertex{
				vertices[j] + pos.x,
				vertices[j + 1] + pos.y,
				vertices[j + 2]
			};

			mesh->addVertex(vertex);
		}

		mesh->addIndices(indices);
		meshes.push_back(mesh);
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	shader.begin();
	shader.setUniform1f("elapsedTime", ofGetElapsedTimef());
	for (const auto& mesh : meshes) {
		mesh->draw();
	}

	shader.end();
	ofDrawBitmapString(ofGetFrameRate(), 100, 100);
}

void ofApp::generateMeshes() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
