#include "s3e.h"
#include "IwDebug.h"
#include "IwUtilInitTerm.h"
#include "IwRuntime.h"

#include <iostream>
#include <GameSparks/GS.h>
#include <GameSparks/IGSPlatform.h>
#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSMessages.h>
#include <GameSparks/MarmaladePlatform.h>

using namespace GameSparks::Core;
using namespace GameSparks::Api::Messages;
using namespace GameSparks::Api::Responses;
using namespace GameSparks::Api::Requests;

void WithdrawChallengeRequest_Response(GameSparks::Core::GS_& gsInstance, const WithdrawChallengeResponse& response)
{
    std::cout << "withdraw challnage: " << std::endl;
    std::cout << response.GetJSONString().c_str() << std::endl;
}

void GetChallengeRequest_Response(GameSparks::Core::GS_& gsInstance, const GetChallengeResponse& response)
{
    std::cout << "get challange data: " << std::endl;
    std::cout << response.GetChallenge().GetJSONString().c_str() << std::endl;
    
    WithdrawChallengeRequest request(gsInstance);
    request.SetChallengeInstanceId(response.GetChallenge().GetChallengeId().GetValue());
    request.SetMessage("automated decline");
    request.Send(WithdrawChallengeRequest_Response);
}

void CreateChallengeRequest_Response(GameSparks::Core::GS_& gsInstance, const GameSparks::Api::Responses::CreateChallengeResponse& response)
{
    std::cout << "challange response: " << response.GetJSONString().c_str() << std::endl;
    
    GetChallengeRequest request(gsInstance);
    request.SetChallengeInstanceId(response.GetBaseData().GetString("challengeInstanceId").GetValue());
    request.Send(GetChallengeRequest_Response);
}

void AuthenticationRequest_Response(GameSparks::Core::GS_& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response)
{
    // when we login successfully, we want to call a custom event
    if (response.GetHasErrors())
    {
        std::cout << "something went wrong during the authentication" << std::endl;
        std::cout << response.GetErrors().GetValue().GetJSON().c_str() << std::endl;
    }
    else
    {
        std::cout << "you successfully authenticated to GameSparks with your credentials" << std::endl;
        std::cout << "your displayname is " << response.GetBaseData().GetString("displayName").GetValue().c_str() << std::endl;
        
        GSDateTime now = GSDateTime::Now();
        
        GameSparks::Api::Requests::CreateChallengeRequest challangeRequest(gsInstance);
        challangeRequest.SetAccessType("PUBLIC");
        challangeRequest.SetChallengeMessage("Ultimate Challange");
        challangeRequest.SetChallengeShortCode("ULTIMATECHALLANGE");
        challangeRequest.SetEndTime(now.AddHours(2).ToGMTime());
        challangeRequest.SetExpiryTime(now.AddMinutes(5).ToGMTime());
        challangeRequest.SetMaxPlayers(5);
        challangeRequest.SetMaxAttempts(5);
        challangeRequest.SetMinPlayers(2);
        challangeRequest.SetSilent(false);
        challangeRequest.SetStartTime(now.AddHours(1).ToGMTime());
        
        challangeRequest.Send(CreateChallengeRequest_Response);
    }
}

void GameSparksAvailable(GameSparks::Core::GS_& gsInstance, bool available)
{
    std::cout << "GameSparks is " << (available ? "available" : "not available") << std::endl;
    
    if (available)
    {
        // login immediately when gamesparks is available

        GameSparks::Api::Requests::AuthenticationRequest request(gsInstance);
        request.SetUserName("abcdefgh");
        request.SetPassword("abcdefgh");
        request.Send(AuthenticationRequest_Response);
    }
}


void OnAchievementEarnedMessage(GameSparks::Core::GS_& gsInstance, const GameSparks::Api::Messages::AchievementEarnedMessage& message)
{
    std::cout << "Achievement earned " << message.GetAchievementName().GetValue().c_str() << std::endl;
}

int main()
{
    // this is here, so that marmalades memory management gets installed. This is needed, so that we can find out, if there are any leaks.
    IwUtilInit();
    
    IW_CALLSTACK("GameSparks Sample")
    {
        // create our GS-instance
        GameSparks::Core::GS_ GS;

        // here we create an instance of MarmaladePlatform. It stores the logs for us. Don't forget to insert your API Key and Secret below.
        MarmaladePlatform gsPlatform("<GameSparks Api Key>", "<GameSparks Api Secret>", true, true, 8);
        GS.Initialise(&gsPlatform);

        //Register our MessageHandler. SetMessageListener "auto-detects" the message type by the second argument to the MessageListener
        GS.SetMessageListener(OnAchievementEarnedMessage);
        
        // this event handler will login the user (see above)
        GS.GameSparksAvailable = GameSparksAvailable;
        
        int64 last_time = s3eTimerGetMs();
        while (!s3eDeviceCheckQuitRequest()) // this is the main loop
        {
            //Update the input systems
            s3eKeyboardUpdate();
            s3ePointerUpdate();
            
            int64 now = s3eTimerGetMs();

            // update out GS-instance
            GS.Update((now-last_time) / 1000.0f);
            last_time = now;
            s3eSurfaceClear(0, 0, 0);
            
            // Your rendering/app code goes here.
            s3eDebugPrint(0, 0, gsPlatform.getLog().c_str(), true);
            
            s3eSurfaceShow();
            
            // Sleep for 0ms to allow the OS to process events etc.
            s3eDeviceYield(0);
        }
        
        // shutdown out GS instance
        GS.ShutDown();
    }
    
    IwUtilTerminate();
}

