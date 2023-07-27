#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	posP1 = new ofVec2f(ofGetWidth()/2 - ofRandom(100,200), 
												ofGetHeight()/2 - ofRandom(50, 150));

	posP2 = new ofVec2f(ofGetWidth() / 2 + ofRandom(100, 200),
												ofGetHeight() / 2 + ofRandom(50, 150));
}

//--------------------------------------------------------------
void ofApp::update(){

	//manejo de inputs
	if (w)
	{
		posP1->y -= 100*ofGetLastFrameTime();
	}
	if (s)
	{
		posP1->y += 100 * ofGetLastFrameTime();
	}
	if (a)
	{
		posP1->x -= 100 * ofGetLastFrameTime();
	}
	if (d)
	{
		posP1->x += 100 * ofGetLastFrameTime();
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(250, 250, 250);
	ofSetColor(255, 0, 0);
	ofCircle(posP1->x, posP1->y, 25);

	ofSetColor(220, 220, 0);
	ofRect(posP2->x, posP2->y, 50, 50);

	//mostrar si es cliente o servidor
	ofSetColor(255, 0, 0);
	if (isServer)
	{
		ofDrawBitmapString("SERVIDOR", 20, 20);
	}
	else
	{
		ofDrawBitmapString("CLIENT", 20, 20);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'w')  w = true;
	if (key == 's')  s = true;
	if (key == 'a')  a = true;
	if (key == 'd')  d = true;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w')  w = false;
	if (key == 's')  s = false;
	if (key == 'a')  a = false;
	if (key == 'd')  d = false;

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
