#pragma once

#include "GameSparks/gsstl.h"
#include "IGameSparks.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "GameSparksComponent.h"


DECLARE_LOG_CATEGORY_EXTERN(UGameSparksModuleLog, Log, All);

class UGameSparksModule : public IGameSparks, public FTickableGameObject
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule();
	virtual void ShutdownModule();

	/** FTickableGameObject implementation */
	virtual bool IsTickableWhenPaused() const;
	virtual bool IsTickableInEditor() const;
	virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;

	/* Initialization and destruction of gamesparks */
	void Initialize(FString apikey, FString secret, bool previewServer);
	void Shutdown();

	static UGameSparksModule* GetModulePtr();

	void SendGameSparksAvailableToComponents(bool available);
	void SendDebugLogToComponents(const gsstl::string& message);


	DECLARE_DELEGATE_OneParam(FTestingEventCallback, bool /* bQueryWasSuccessful */);

	/**
	* Asynchronously queries a list of live streams that are currently in progress for the specified game name.  Note that some
	* services may not support this feature.  Your callback function will be called with the list of live streams that were found.
	* In the case there was an error or this feature wasn't supported, your callback will still be executed but will contain
	* a status variable that indicates failure
	*
	* @param	GameName				The name of the game to search for
	* @param	CompletionCallback		The function to invoke when the query has finished (or if an error occurs)
	*/
	virtual void TestingEvent(const FString& GameName);

private:
	// iterate over the worlds and get all gamesparks components
	TArray<UGameSparksComponent*> GetGameSparksComponents();

	// we need to notified when worlds are created and destroyed
	static void OnWorldCreated(UWorld* World, const UWorld::InitializationValues IVS);
	static void OnWorldDestroyed(UWorld* World);
};