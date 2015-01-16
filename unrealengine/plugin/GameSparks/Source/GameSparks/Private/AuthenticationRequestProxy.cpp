#include "GameSparksPrivatePCH.h"
#include "AuthenticationRequestProxy.h"
#include "GameSparks/generated/GSRequests.h"

// this is a temp fix, because the iOS Version is not supporting std function
// we will put this right 
UAuthenticationRequestProxy* g_proxy = NULL;

UAuthenticationRequestProxy::UAuthenticationRequestProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    g_proxy = this;
}


UAuthenticationRequestProxy* UAuthenticationRequestProxy::SendAuthenticationRequest(const FString& UserName, const FString& Password)
{
	UAuthenticationRequestProxy* Proxy = NewObject<UAuthenticationRequestProxy>();
	Proxy->UserName = UserName;
	Proxy->Password = Password;

	return Proxy;
}

void send(const GameSparks::Api::Responses::AuthenticationResponse& response)
{
    FAuthenticationResponse2 unreal_response;
    unreal_response.DisplayName = response.GetDisplayName().GetValue().c_str();
    unreal_response.GetAuthToken = response.GetAuthToken().GetValue().c_str();
    unreal_response.SwitchSummary.Id = response.GetSwitchSummary().GetId().GetValue().c_str();
    
    if (response.GetHasErrors())
    {
        g_proxy->OnAuthenticationResponse.Broadcast(unreal_response, false);
    }
    else
    {
        g_proxy->OnAuthenticationResponse.Broadcast(unreal_response, true);
    }
}



void UAuthenticationRequestProxy::Activate()
{
	GameSparks::Api::Requests::AuthenticationRequest requestWrong;
	requestWrong.SetUserName(TCHAR_TO_ANSI(*UserName));
	requestWrong.SetPassword(TCHAR_TO_ANSI(*Password));
    requestWrong.Send(send);
	/*requestWrong.Send([&](const GameSparks::Api::Responses::AuthenticationResponse& response)
	{
		FAuthenticationResponse2 unreal_response;
		unreal_response.DisplayName = response.GetDisplayName().GetValue().c_str();
		unreal_response.GetAuthToken = response.GetAuthToken().GetValue().c_str();
		unreal_response.SwitchSummary.Id = response.GetSwitchSummary().GetId().GetValue().c_str();

		if (response.GetHasErrors())
		{
			this->OnAuthenticationResponse.Broadcast(unreal_response, false);
		}
		else
		{
			this->OnAuthenticationResponse.Broadcast(unreal_response, true);
		}
	});*/
}
