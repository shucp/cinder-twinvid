#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/qtime/QuickTime.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TwinvidApp : public AppNative {
  public:
	void prepareSettings(Settings *settings);
	void setup();
	void update();
	void draw();

	// event
	void keyDown(KeyEvent event);

	// original function
	void openVideo(qtime::MovieGlRef &mov);

	// member
	qtime::MovieGlRef playingMov, movA, movB;
	char lastPressedKey;
	gl::Texture frame;
};

void TwinvidApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize(300, 300);
	settings->setFrameRate(30.0f);
}

void TwinvidApp::setup()
{
	openVideo(movA);
	openVideo(movB);

	gl::enableAlphaBlending();
	gl::clear( Color( 0, 0, 0 ) ); 
}

void TwinvidApp::update()
{
	if (lastPressedKey) {
		playingMov = movB;
		lastPressedKey = NULL;
	} else {
		playingMov = movA;
	}

	if (playingMov) {
		frame = playingMov->getTexture();
	}
}

void TwinvidApp::draw()
{
	gl::draw(frame, getWindowBounds());
}

void TwinvidApp::keyDown(KeyEvent event)
{
	switch (event.getChar()) {
		case KeyEvent::KEY_ESCAPE:
			exit(0);
			break;

		case KeyEvent::KEY_RETURN:
			setFullScreen(!isFullScreen());
			break;

		default:
			lastPressedKey = event.getChar();
	}
}

void TwinvidApp::openVideo(qtime::MovieGlRef &mov)
{
	string p = getOpenFilePath().string();
	if (!p.empty()) {
		mov = qtime::MovieGl::create(p);
		mov->setLoop();
		mov->play();
	}
}

CINDER_APP_NATIVE( TwinvidApp, RendererGl )
