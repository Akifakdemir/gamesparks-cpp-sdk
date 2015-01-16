#pragma once

#include "GSUERequest.h"
#include "GameSparksComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class GAMESPARKS_API UGameSparksComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UGameSparksComponent(const class FObjectInitializer& ObjectInitializer);

	virtual void Activate(bool bReset = false);

	virtual void Deactivate();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);

	virtual void BeginDestroy() override;


	UPROPERTY(Transient)
	UBillboardComponent* BillboardSubComponent;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksAvailable, bool, available);

	// this delegate is called by gamesparks when the availability changed
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksAvailable OnGameSparksAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksLogEvent, FString, logMessage);

	//  called by gamesparks when a new log message was generated, useful for debugging
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksLogEvent OnGameSparksLogEventDelegate;

	UFUNCTION(Category = GameSparks, BlueprintCallable)
	void Connect(FString apikey, FString secret, bool previewServer);

	UFUNCTION(Category = GameSparks, BlueprintCallable)
	void Disconnect();

	UFUNCTION(Category = GameSparks, BlueprintCallable)
	void SendRequest(UGSUERequest* request);



	UFUNCTION(Category = GameSparks, BlueprintCallable)
	void SendAuthenticationRequest(FString username, FString password);
};