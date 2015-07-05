#pragma once
#include "GameSparksPrivatePCH.h"
#include "GameSparksScriptData.h"
#include "GSFindMatchRequest.h"

void FindMatchRequestResponseCallback(GameSparks::Core::GS_& gsInstance, const GameSparks::Api::Responses::FindMatchResponse& response){
    
    FGSFindMatchResponse unreal_response = FGSFindMatchResponse(response.GetBaseData());
    
    UGSFindMatchRequest* g_UGSFindMatchRequest = static_cast<UGSFindMatchRequest*>(response.GetUserData());
                                             
    if (response.GetHasErrors())
    {
        g_UGSFindMatchRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFindMatchRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFindMatchRequest* UGSFindMatchRequest::SendFindMatchRequest(FString MatchGroup, FString MatchShortCode, int32 Skill,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
	UGSFindMatchRequest* proxy = NewObject<UGSFindMatchRequest>();
	proxy->matchGroup = MatchGroup;
	proxy->matchShortCode = MatchShortCode;
	proxy->skill = Skill;
	proxy->scriptData = ScriptData;
	proxy->durable = Durable;
	proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
	return proxy;
}
	
void UGSFindMatchRequest::Activate()
{
	GameSparks::Api::Requests::FindMatchRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
	if(matchGroup != ""){
		gsRequest.SetMatchGroup(TCHAR_TO_UTF8(*matchGroup));
	}
	if(matchShortCode != ""){
		gsRequest.SetMatchShortCode(TCHAR_TO_UTF8(*matchShortCode));
	}
	if(skill != 0){
		gsRequest.SetSkill(skill);
	}
	if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
    	gsRequest.SetDurable(durable);
    }
    
    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
    	gsRequest.Send(FindMatchRequestResponseCallback, requestTimeoutSeconds);	
    } else {
    	gsRequest.Send(FindMatchRequestResponseCallback);
    }
	
	
	
}

UGSFindMatchRequest::UGSFindMatchRequest(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP) {
}

