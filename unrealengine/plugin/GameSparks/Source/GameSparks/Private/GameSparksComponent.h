#pragma once

#include "GSTypes.h"
#include "Components/SceneComponent.h"
#include "GameSparksComponent.generated.h"

UCLASS(ClassGroup=(GameSparks), meta = (BlueprintSpawnableComponent))
class GAMESPARKS_API UGameSparksComponent : public USceneComponent
{
	GENERATED_BODY()

public:

    UGameSparksComponent();
    
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Connect(FString apikey, FString secret, bool previewServer);
    
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Disconnect();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksAvailable, bool, available);

	// this delegate is called by gamesparks when the availability changed
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksAvailable OnGameSparksAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksLogEvent, FString, logMessage);

	//  called by gamesparks when a new log message was generated, useful for debugging
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksLogEvent OnGameSparksDebugLog;
    
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAuthenticated();
    
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAvailable();

};