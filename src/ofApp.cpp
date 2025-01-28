#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//configurar menu
	mainmenu.setup();
	mainmenu.add(ButtonServer.setup("Create server"));
	mainmenu.add(ButtonClient.setup("Join game"));
	mainmenu.setPosition(ofGetWidth() / 2 - mainmenu.getWidth() / 2,
											ofGetHeight() / 2 - mainmenu.getHeight() / 2);
	ButtonClient.addListener(this, &ofApp::ConnectClient);
	ButtonServer.addListener(this, &ofApp::CreateServer);

	posP1 = new ofVec2f(ofGetWidth()/2 - ofRandom(100,200), 
												ofGetHeight()/2 - ofRandom(50, 150));

	posP2 = new ofVec2f(ofGetWidth() / 2 + ofRandom(100, 200),
												ofGetHeight() / 2 + ofRandom(50, 150));

	appState = EAppState::menu;
}
void ofApp::CreateServer()
{
	puts("Creando servidor de juego");
	appState = EAppState::server;
	udpManager.Create();
	udpManager.Bind(PORT);
	udpManager.SetNonBlocking(true);
}

void ofApp::ConnectClient()
{
	puts("Intentando conectar a partida");
	appState = EAppState::client;
	string serverIP = ofSystemTextBoxDialog("IP Address:", "127.0.0.1");
	udpManager.Create();
	udpManager.Connect(serverIP.c_str(), PORT);
	udpManager.SetNonBlocking(true);
}

//--------------------------------------------------------------
void ofApp::update(){

	//server maneja al P1, client maneja al P2
	if (appState == server) {
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
			//enviar esta posicion 
			memset(buffer, 0, BUFFER_SIZE);
			sprintf(buffer, "%f,%f", posP1->x, posP1->y);
			udpManager.SendAll(buffer, BUFFER_SIZE);
			//recibir la del p2
			memset(buffer, 0, BUFFER_SIZE);
			
			bool getNext = true;
			while (getNext)
			{
				udpManager.Receive(buffer, BUFFER_SIZE);

				if (strcmp(buffer, "")==0)
				{
					getNext = false;
				}
				else
				{
					strcpy(bufferLast, buffer);
				}
			}
			printf("received: %s \n", bufferLast);
			char* temp;
			temp = strtok(bufferLast, ",");
			if (temp != NULL)
			{
				posP2->x = atof(temp);
				temp = strtok(NULL, ",");
				if (temp != NULL)
					posP2->y = atoi(temp);
			}		
	}
	else if (appState == client)
	{
		if (w)
		{
			posP2->y -= 100 * ofGetLastFrameTime();
		}
		if (s)
		{
			posP2->y += 100 * ofGetLastFrameTime();
		}
		if (a)
		{
			posP2->x -= 100 * ofGetLastFrameTime();
		}
		if (d)
		{
			posP2->x += 100 * ofGetLastFrameTime();
		}

		//enviar datos
		memset(buffer, 0, BUFFER_SIZE);
		sprintf(buffer, "%f,%f", posP2->x, posP2->y);
		udpManager.Send(buffer, BUFFER_SIZE);
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (appState == EAppState::menu)
	{
		ofBackground(28, 28, 28);
		ofDrawBitmapString("menu", 20, 20);
		mainmenu.draw();
	}
	else{

		ofBackground(28, 28, 28);
		ofSetColor(255, 0, 0);
		ofCircle(posP1->x, posP1->y, 25);

		ofSetColor(220, 220, 0);
		ofRect(posP2->x, posP2->y, 50, 50);

		//mostrar si es cliente o servidor
		ofSetColor(255, 255, 255);
		if (appState == server)
		{
			ofDrawBitmapString("SERVER", 20, 20);
		}
		else
		{
			ofDrawBitmapString("CLIENT", 20, 20);
		}
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
