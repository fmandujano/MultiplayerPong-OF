#include "ofMain.h"
#include "ofApp.h"

//NOTA: Recuerda deshabilitar vcpk en las opciones de cada proyecto 
// Properties / Configuration Properties / vcpkg / use vcpkg NO
//Un proyecto de OF incluye sus propias bibliotecas

//========================================================================
int main(int argc, char** argv )
{
	ofSetupOpenGL(640,480,OF_WINDOW);			// <-------- setup the GL context

	ofApp* myApp = new ofApp();

	if (argc > 1)
	{
		if (strcmp(argv[1], "server")==0   )
		{
			myApp->isServer = true;
		}
	}

	ofRunApp(myApp);

}
