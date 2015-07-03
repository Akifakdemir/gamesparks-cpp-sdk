#pragma once
#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSListInviteFriendsRequest.h"

void ListInviteFriendsRequestResponseCallback(GameSparks::Core::GS_& gsInstance, const GameSparks::Api::Responses::ListInviteFriendsResponse& response){
    
    FGSListInviteFriendsResponse unreal_response = FGSListInviteFriendsResponse(response.GetBaseData());

	UGSListInviteFriendsRequest* g_UGSListInviteFriendsRequest = static_cast<UGSListInviteFriendsRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSListInviteFriendsRequest->OnResponse.Broadcast(unreal_response, false);
    }
    else
    {
        g_UGSListInviteFriendsRequest->OnResponse.Broadcast(unreal_response, true);
    }
}

UGSListInviteFriendsRequest* UGSListInviteFriendsRequest::SendListInviteFriendsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSListInviteFriendsRequest* proxy = NewObject<UGSListInviteFriendsRequest>();
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSListInviteFriendsRequest::Activate()
{
	GameSparks::Api::Requests::ListInviteFriendsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);
    
    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(ListInviteFriendsRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(ListInviteFriendsRequestResponseCallback);
    }
    
	
}

UGSListInviteFriendsRequest::UGSListInviteFriendsRequest(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP) {
}

