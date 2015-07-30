#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

#include "GameSparksComponent.h"
#include "GameSparksModule.h"

// Sets default values for this component's properties
UGameSparksComponent::UGameSparksComponent()
{
    bWantsInitializeComponent = true;
    PrimaryComponentTick.bCanEverTick = false;
}

void UGameSparksComponent::Connect(FString apikey, FString secret, bool previewServer)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::OnWorldConnected(GetWorld());
		UGameSparksModule::GetModulePtr()->Initialize(apikey, secret, previewServer);
        
    }
}

void UGameSparksComponent::Disconnect()
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::OnWorldDisconnected(GetWorld());
        UGameSparksModule::GetModulePtr()->Shutdown();
    }
		
}

bool UGameSparksComponent::IsAuthenticated(){
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAuthenticated();
    }
    return false;

}

bool UGameSparksComponent::IsAvailable(){
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAvailable();
    }
    return false;
}


