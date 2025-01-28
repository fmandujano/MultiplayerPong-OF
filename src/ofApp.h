#pragma once

#include "ofMain.h"
#include <ofxGui.h>
#include <ofxNetwork.h>
#define BUFFER_SIZE 64

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//entidades del jugador
		ofVec2f  *posP1, *posP2;

		//estado de las teclas
		bool w, s, a, d;

		//modo de juego
		bool isServer = false;	

		//menu de seleccion de modo
		enum EAppState {
			menu, client, server
		} appState;

		ofxPanel mainmenu;
		ofxButton ButtonServer;
		ofxButton ButtonClient;

		//listeners de botones
		void CreateServer();
		void ConnectClient();

		//cosas de networking o red
		ofxUDPManager udpManager;
		short int PORT = 6666; //max 65535
		//buffer para guardar los mensajes de la red
		char buffer[BUFFER_SIZE];
		char bufferLast[BUFFER_SIZE];

};
