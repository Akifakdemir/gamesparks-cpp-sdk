#pragma once

#include "OnlineBlueprintCallProxyBase.h"
#include "GSUEData.h"
#include "AuthenticationRequestProxy.generated.h"

USTRUCT(BlueprintType)
struct FAuthenticationResponse2_FPlayer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse|Player")
	TArray<FString> Achievements;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse|Player")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse|Player")
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse|Player")
	bool Online;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse|Player")
	TArray<FString> VirtualGoods;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks")
	UGSUEData* SomeData;
};

USTRUCT(BlueprintType)
struct FAuthenticationResponse2
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse")
	FString GetAuthToken;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse")
	FAuthenticationResponse2_FPlayer SwitchSummary;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameSparks|AuthenticationResponse")
	FString UserId;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAuthenticationRequestCompleted, FAuthenticationResponse2, response, bool, successful);

UCLASS()
class UAuthenticationRequestProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintAssignable)
	FOnAuthenticationRequestCompleted OnAuthenticationResponse;

	UFUNCTION(BlueprintCallable, Category = "GameSparks", meta = (BlueprintInternalUseOnly = "true"))
	static UAuthenticationRequestProxy* SendAuthenticationRequest(const FString& UserName, const FString& Password);

	/** UOnlineBlueprintCallProxyBase interface */
	virtual void Activate() override;

protected:

	/** Name of the game that we're querying about */
	FString UserName;
	FString Password;
};