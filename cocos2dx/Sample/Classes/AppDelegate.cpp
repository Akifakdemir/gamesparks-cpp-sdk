#include "AppDelegate.h"
#include "HelloWorldScene.h"

// NOTE: It's important, that this file is included *AFTER* cocos related files have been included.
// Also note: some features like unique device id are currently not implemented. You might want to inherit
// from GameSparks::Core::Cocos2dxPlatform and implement the methods in questiion.
#include <GameSparks/generated/GSRequests.h>

#ifdef WIN32

// touch
// also link openssl
#	pragma comment(lib, "libeay32.lib")
#	pragma comment(lib, "ssleay32.lib")

#endif /* WIN32 */

USING_NS_CC;

AppDelegate::AppDelegate() {
    g_screenLog = new ScreenLog();
    g_screenLog->setLevelMask( LL_TRACE | LL_DEBUG | LL_INFO | LL_WARNING | LL_ERROR | LL_FATAL );
    g_screenLog->setFontFile( "UbuntuMono-R.ttf" );
    g_screenLog->setTimeoutSeconds( 15 );
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// *GS* Callback for GameSparks::Api::Requests::AuthenticationRequest.Send()
void AuthenticationRequest_Response(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response)
{
	if (response.GetHasErrors())
	{
		cocos2d::log("something went wrong during the authentication");
		cocos2d::log("%s", response.GetErrors().GetValue().GetJSON().c_str());
	}
	else
	{
		cocos2d::log("you successfully authenticated to GameSparks with your credentials");
		cocos2d::log("your displayname is %s.", response.GetBaseData().GetString("displayName").GetValue().c_str());
	}
}

// *GS* this function gets called by the SDK.
void OnGameSparksAvailable(GameSparks::Core::GS& gsInstance, bool available)
{
	//std::cout << "GameSparks is " << (available ? "available" : "not available") << std::endl;
	cocos2d::log("GameSparks is %s.", (available ? "available" : "not available"));

	// try with wrong credentials
	GameSparks::Api::Requests::AuthenticationRequest requestWrong(gsInstance);
	requestWrong.SetUserName("TOTALLYWRONGUSER");
	requestWrong.SetPassword("TOTALLYWRONGPASSWORD");
	requestWrong.Send(AuthenticationRequest_Response);

	// try with right credentials
	GameSparks::Api::Requests::AuthenticationRequest requestRight(gsInstance);
	requestRight.SetUserName("abcdefgh");
	requestRight.SetPassword("abcdefgh");
	requestRight.Send(AuthenticationRequest_Response);
}


bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("GameSparks Cocos2d-x Sample");
        director->setOpenGLView(glview);
    }

	{	// *GS* initialize GameSparks
		using namespace GameSparks::Core;

		// register our callback
		gsupdater.GS.GameSparksAvailable = OnGameSparksAvailable;

		// register our updater
		director->getScheduler()->scheduleUpdate(&gsupdater, 0, false);
	}

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    g_screenLog->attachToScene( scene );

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
