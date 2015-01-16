#pragma once

#include "GSActor.generated.h"

/************************************************************************/
/* This is a sample actor, which shows how to use GameSpark directly	*/
/* in C++ code without the component									*/
/************************************************************************/

UCLASS()
class AGSActor : public AActor
{
	GENERATED_BODY()

public:
	AGSActor(const class FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);



	UPROPERTY(Transient)
	UBillboardComponent* BillboardSubComponent;
};
