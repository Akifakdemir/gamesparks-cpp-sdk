

#include "GameSparksPrivatePCH.h"
#include "GameSparksModule.h"
#include "ModuleManager.h"
#include "Runtime/Core/Public/Features/IModularFeatures.h"
#include "Runtime/Core/Public/Stats/Stats2.h"

#include "GameSparksComponent.h"

#include "GameSparks/GS.h"
#include "GSUnrealPlatform.h"
#include <functional>

using namespace GameSparks::Core;
using namespace GameSparks::UnrealEngineSDK;

//DEFINE_LOG_CATEGORY(FGameSparks);
IMPLEMENT_MODULE(UGameSparksModule, GameSparks);
#define LOCTEXT_NAMESPACE "GameSparksPlugin"

DEFINE_LOG_CATEGORY(UGameSparksModuleLog);

namespace UGameSparksModuleNS
{
	//static TMap< UWorld*, UPaperBatchComponent* > WorldToBatcherMap;

	static TArray< UWorld* > WorldList;

	static FWorldDelegates::FWorldInitializationEvent::FDelegate OnWorldCreatedDelegate;
	static FWorldDelegates::FWorldEvent::FDelegate OnWorldDestroyedDelegate;
}

void GameSparksAvailable_Static(GameSparks::Core::GS_& gsInstance, bool available)
{
	UGameSparksModule::GetModulePtr()->SendGameSparksAvailableToComponents(available);
}

void UGameSparksModule::StartupModule()
{	
	GS.GameSparksAvailable = GameSparksAvailable_Static;

	UGameSparksModuleNS::OnWorldCreatedDelegate = FWorldDelegates::FWorldInitializationEvent::FDelegate::CreateStatic(&UGameSparksModule::OnWorldCreated);
	FWorldDelegates::OnPostWorldInitialization.Add(UGameSparksModuleNS::OnWorldCreatedDelegate);

	UGameSparksModuleNS::OnWorldDestroyedDelegate = FWorldDelegates::FWorldEvent::FDelegate::CreateStatic(&UGameSparksModule::OnWorldDestroyed);
	FWorldDelegates::OnPreWorldFinishDestroy.Add(UGameSparksModuleNS::OnWorldDestroyedDelegate);

	UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::StartupModule"));

}

void UGameSparksModule::ShutdownModule()
{
	GS.ShutDown();
}

bool UGameSparksModule::IsTickableWhenPaused() const
{
	return true;
}

bool UGameSparksModule::IsTickableInEditor() const
{
	return true;
}

void UGameSparksModule::Tick(float DeltaTime)
{
	GS.Update(DeltaTime);
}

bool UGameSparksModule::IsTickable() const
{
	return true;
}

TStatId UGameSparksModule::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGameSparksModule, STATGROUP_Tickables);
}

void UGameSparksModule::Initialize(FString apikey, FString secret, bool previewServer)
{
	GS.Initialise(new GSUnrealPlatform(TCHAR_TO_ANSI(*apikey), TCHAR_TO_ANSI(*secret), previewServer));
}

void UGameSparksModule::Shutdown()
{
	GS.ShutDown();
}

UGameSparksModule* UGameSparksModule::GetModulePtr()
{
	return FModuleManager::GetModulePtr<UGameSparksModule>("GameSparks");
}

void UGameSparksModule::SendGameSparksAvailableToComponents(bool available)
{
	for (UGameSparksComponent* gsComponent : GetGameSparksComponents())
	{
		gsComponent->OnGameSparksAvailableDelegate.Broadcast(available);
	}
}

void UGameSparksModule::SendDebugLogToComponents(const gsstl::string& message)
{
	FString str = FString(message.c_str());
	if (GEngine != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *str);

		for (UGameSparksComponent* gsComponent : GetGameSparksComponents())
		{
			gsComponent->OnGameSparksLogEventDelegate.Broadcast(str);
		}
	}
}

TArray<UGameSparksComponent*> UGameSparksModule::GetGameSparksComponents()
{
	TArray<UGameSparksComponent*> result;
	for (int32 i = 0; i < UGameSparksModuleNS::WorldList.Num(); ++i)
	{
		UWorld* world = UGameSparksModuleNS::WorldList[i];

		for (TActorIterator<AActor> ActorItr(world); ActorItr; ++ActorItr)
		{
			UGameSparksComponent* comp = dynamic_cast<UGameSparksComponent*>(ActorItr->GetComponentByClass(UGameSparksComponent::StaticClass()));
			if (comp != nullptr)
			{
				result.Add(comp);
			}
		}
	}
	return result;
}

void UGameSparksModule::OnWorldCreated(UWorld* World, const UWorld::InitializationValues IVS)
{
	UGameSparksModuleNS::WorldList.Add(World);
}

void UGameSparksModule::OnWorldDestroyed(UWorld* World)
{
	UGameSparksModuleNS::WorldList.Remove(World);
}

void UGameSparksModule::TestingEvent(const FString& GameName)
{

}
