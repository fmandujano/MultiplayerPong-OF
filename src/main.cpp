#include "ofMain.h"
#include "ofApp.h"

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
