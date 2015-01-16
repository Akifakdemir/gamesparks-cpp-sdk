#pragma once

#include "GSUERequest.generated.h"

UCLASS(BlueprintType)
class UGSUERequest : public UObject
{
	GENERATED_BODY()
public:
	UGSUERequest(const class FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "GameSparks|Requests", meta = (WorldContext = "WorldContext"))
	static float DoAnything() ;


	
};