#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "ScreenLog.h"

// *GS* includes needed for GameSparks
#include <GameSparks/GS.h>

// NOTE: It's important, that this file is included *AFTER* cocos related files have been included.
// Also note: some features like unique device id are currently not implemented. You might want to inherit
// from GameSparks::Core::Cocos2dxPlatform and implement the methods in questiion.
#include <GameSparks/Cocos2dxPlatform.h>
#include <GameSparks/generated/GSRequests.h>


/*!
* This class uses the ScreenLog class from iforce2d.net to perform on-screen logging.
* This is also an example on how to customize Cocos2dxPlatform
* */
class OnScreenLoggingCocosPlatform : public GameSparks::Core::Cocos2dxPlatform
{
    public:
        // use constructor of base class (C++11)
        using GameSparks::Core::Cocos2dxPlatform::Cocos2dxPlatform;

        virtual void DebugMsg(const gsstl::string& message) const override
        {
            Cocos2dxPlatform::DebugMsg(message);
            if(g_screenLog)
            {
                // the iforce2d screen log class does not cope with newlines to well, so we split messages up here
                std::stringstream ss(message);
                std::string line;
                while (std::getline(ss, line))
                {
                    g_screenLog->log(LL_TRACE, "%s", line.c_str());
                }
            }
        }
};


/*
	*GS*
	This links to the correct variant GameSparks libary on windows. 
	If you get a linker error, please check that you've compiled the GameSparks
	Library and that the correct path is setup in the linker settings.
*/
#ifdef WIN32
#	ifdef _DEBUG
#		pragma comment(lib, "Gamesparks_d.lib")
#	else
#		pragma comment(lib, "Gamesparks.lib")
#	endif /* _DEBUG */

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

/*
	*GS*
    
    This is a little helper class, that holds the GS-instance and platform.
    It's also here to convert Update to update, so that we can
	update gamesparks via scheduleUpdate.
 
*/
struct GameSparksCocos
{
    GameSparksCocos()
    :platform("<insert-your-api-key-here>", "<insert-your-api-secret-here>", true, true)
    {
        GS.Initialise(&platform);
    }

    // if you don't want on-screen logging, you can simply use GameSparks::Core::Cocos2dxPlatform
    //GameSparks::Core::Cocos2dxPlatform platform;
    OnScreenLoggingCocosPlatform platform;

    GameSparks::Core::GS GS;
    
	void update(float dt)
	{
		GS.Update(dt);
	}
} gsupdater;


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
