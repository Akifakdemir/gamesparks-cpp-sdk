#include <iostream>

#include <GameSparks/GS.h>
#include <GameSparks/IGSPlatform.h>
#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSMessages.h>

#include "./extra/usleep.h"
#include "sample_configuration.h"

using namespace GameSparks::Core;
using namespace GameSparks::Api::Messages;
using namespace GameSparks::Api::Responses;
using namespace GameSparks::Api::Requests;

void WithdrawChallengeRequest_Response(const WithdrawChallengeResponse& response)
{
	std::cout << "withdraw challnage: " << std::endl;
	std::cout << response.GetJSONString().c_str() << std::endl;
}

void GetChallengeRequest_Response(const GetChallengeResponse& response)
{
	std::cout << "get challange data: " << std::endl;
	std::cout << response.GetChallenge().GetJSONString().c_str() << std::endl;

	WithdrawChallengeRequest request;
	request.SetChallengeInstanceId(response.GetChallenge().GetChallengeId().GetValue());
	request.SetMessage("automated decline");
	request.Send(WithdrawChallengeRequest_Response);
}

void CreateChallengeRequest_Response(const GameSparks::Api::Responses::CreateChallengeResponse& response)
{
	std::cout << "challange response: " << response.GetJSONString().c_str() << std::endl;

	GetChallengeRequest request;
	request.SetChallengeInstanceId(response.GetBaseData().GetString("challengeInstanceId").GetValue());
	request.Send(GetChallengeRequest_Response);
}

void AuthenticationRequest_Response(const GameSparks::Api::Responses::AuthenticationResponse& response)
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

		GameSparks::Api::Requests::CreateChallengeRequest challangeRequest;
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

void GameSparksAvailable(bool available)
{
	std::cout << "GameSparks is " << (available ? "available" : "not available") << std::endl;
	
	if (available)
	{
		// login immediately when gamesparks is available

		// this does not work! when request gets out of scope, all data goes with it.
		GameSparks::Api::Requests::AuthenticationRequest request;
		request.SetUserName("abcdefgh");
		request.SetPassword("abcdefgh");
		request.Send(AuthenticationRequest_Response);
	}
}

void OnAchievementEarnedMessage(const GameSparks::Api::Messages::AchievementEarnedMessage& message)
{
	std::cout << "Achievement earned " << message.GetAchievementName().GetValue().c_str() << std::endl;
}

int main(int argc, const char* argv[])
{
	GS.Initialise(new SampleConfiguration::NativePlatformDescription());

	// this event handler will login the user (see above)
	GS.GameSparksAvailable = GameSparksAvailable;

	AchievementEarnedMessage::SetListener(OnAchievementEarnedMessage);

	int cyclesLeft = 200000;
	while (cyclesLeft-- > 0)
	{
		// update the webclient (polling)
		GS.Update(100);

		usleep(100);
	}

	GS.ShutDown();
}


