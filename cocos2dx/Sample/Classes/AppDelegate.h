#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

// *GS* includes needed for GameSparks
#include <GameSparks/GS.h>
#include <GameSparks/Cocos2dxPlatform.h>

#include "ScreenLog.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

private:
    /*
    *GS*
    
    This is a little helper class, that holds the GS-instance and platform.
    It's also here to convert Update to update, so that we can
    update gamesparks via scheduleUpdate.
 
    */
    struct GameSparksCocos
    {
        /*!
        * This class uses the ScreenLog class from iforce2d.net to perform on-screen logging.
        * This is also an example on how to customize Cocos2dxPlatform
        * */
        class OnScreenLoggingCocosPlatform : public GameSparks::Core::Cocos2dxPlatform
        {
            public:
                // use constructor of base class (C++11)
                //using GameSparks::Core::Cocos2dxPlatform::Cocos2dxPlatform;
				OnScreenLoggingCocosPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool usePreviewServer, bool verboseLogging = false)
					:GameSparks::Core::Cocos2dxPlatform(apikey, secret, usePreviewServer, verboseLogging){}

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
    };

    GameSparksCocos gsupdater;
};

#endif // _APP_DELEGATE_H_

