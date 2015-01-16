#include <iostream>

#include <GameSparks/GS.h>
#include <GameSparks/IGSPlatform.h>
#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSMessages.h>

#include "./extra/usleep.h"
#include "sample_configuration.h"



/* this is a request of a custom event, which adds and remove an achievement for the player 
	
	Event Data:
		Short COde: GETACHIEVEMENT
		Name: Get Achievement
		Description: Add and remove an achievement to the player

		Properties:
			Name: Achievement Name
			Short Code: ACHIEVEMENTNAME
			Data Type: String
			Default Calc: Used in Script

	Cloud Code:
		
		var player = Spark.getPlayer();

		player.addAchievement(Spark.getData().ACHIEVEMENTNAME);
		player.removeAchievement(Spark.getData().ACHIEVEMENTNAME);

*/

class GetAchievementResponse : public GameSparks::Core::GSTypedResponse
{
public:
	GetAchievementResponse(const  GameSparks::Core::GSData& data)
		: GSTypedResponse(data)
	{

	}

	GetAchievementResponse(const GetAchievementResponse& other)
		: GSTypedResponse(other)
	{
	}
};

class GetAchievementRequest : public GameSparks::Core::GSTypedRequest < GetAchievementRequest, GetAchievementResponse >
{
public:
	GetAchievementRequest()
		: GSTypedRequest()
	{
		m_Request.AddString("eventKey", "GETACHIEVEMENT");
	}

	GetAchievementRequest& SetAchievementName(const gsstl::string& achievementName)
	{
		m_Request.AddString("ACHIEVEMENTNAME", achievementName);
		return *this;
	}
};

void GetAchievementRequest_Repsonse(const GetAchievementResponse& response)
{
	std::cout << response.GetBaseData().GetJSON().c_str() << std::endl;
}



void ListAchievementsRequest_Response(const GameSparks::Api::Responses::ListAchievementsResponse& response)
{
	std::cout << response.GetBaseData().GetJSON().c_str() << std::endl;

	auto achievements = response.GetAchievements();

	for (gsstl::vector<GameSparks::Api::Responses::ListAchievementsResponse::_Achievement>::iterator it = achievements.begin(); it != achievements.end(); ++it)
	{
		std::cout << it->GetName().GetValue().c_str() << std::endl;
	}

	// create and send an custom event which will add and remove an achievement
	GetAchievementRequest request;
	request.SetAchievementName("MYACHIEVEMENT");
	request.Send(GetAchievementRequest_Repsonse);

	
}

void AuthenticationRequest_Response(const GameSparks::Api::Responses::AuthenticationResponse& response)
{
	// when we login successully, we want to call a custom event
	if (response.GetHasErrors())
	{
		std::cout << "something went wrong during the authentication" << std::endl;
		std::cout << response.GetErrors().GetValue().GetJSON().c_str() << std::endl;
	}
	else
	{
		std::cout << "you successfully authenticated to GameSparks with your credentials" << std::endl;
		std::cout << "your displayname is " << response.GetBaseData().GetString("displayName").GetValue().c_str() << std::endl;

		// get all achievements for the player
		GameSparks::Api::Requests::ListAchievementsRequest request;
		request.Send(ListAchievementsRequest_Response);
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
	using namespace GameSparks::Core;
	using namespace GameSparks::Api::Messages;

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


