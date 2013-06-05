#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TwinvidApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void TwinvidApp::setup()
{
}

void TwinvidApp::mouseDown( MouseEvent event )
{
}

void TwinvidApp::update()
{
}

void TwinvidApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( TwinvidApp, RendererGl )
