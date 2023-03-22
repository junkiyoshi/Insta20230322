#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int x = -300; x <= 300; x += 30) {

		for (int y = -300; y <= 300; y += 30) {

			ofPushMatrix();
			ofTranslate(x, y);
			ofRotate(15);

			auto noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01);
			noise_value = noise_value < 0.45 ? 0.1 : ofMap(noise_value, 0.45, 1, 0.1, 1);
			auto radius = ofMap(noise_value, 0, 1, 0, 45);

			vector<glm::vec2> vertices;
			vertices.push_back(glm::vec2(radius * cos(45 * DEG_TO_RAD), radius * sin(45 * DEG_TO_RAD)));
			vertices.push_back(glm::vec2(radius * cos(225 * DEG_TO_RAD), radius * sin(225 * DEG_TO_RAD)));
			vertices.push_back(glm::vec2(radius * cos(135 * DEG_TO_RAD), radius * sin(135 * DEG_TO_RAD)));
			vertices.push_back(glm::vec2(radius * cos(315 * DEG_TO_RAD), radius * sin(315 * DEG_TO_RAD)));

			ofDrawLine(vertices[0], vertices[1]);
			ofDrawLine(vertices[2], vertices[3]);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}