#include "GameSparksPrivatePCH.h"
#include "GSActor.h"
#include "GameSparksModule.h"

AGSActor::AGSActor(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//  billboard for the nice gamesparks logo 
	BillboardSubComponent = ObjectInitializer.CreateDefaultSubobject<UBillboardComponent>(this, TEXT("BillboardSubComponent"));
	BillboardSubComponent->Mobility = EComponentMobility::Movable;
	BillboardSubComponent->AttachTo(this->RootComponent);
	BillboardSubComponent->Sprite = ConstructorHelpers::FObjectFinderOptional<UTexture2D>(TEXT("/GameSparks/gs_icon")).Get();
}

void AGSActor::BeginPlay()
{
	if (UGameSparksModule::GetModulePtr() != nullptr)
		UGameSparksModule::GetModulePtr()->Initialize("APIKEY","SECRET" , true);
}

void AGSActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UGameSparksModule::GetModulePtr() != nullptr)
		UGameSparksModule::GetModulePtr()->Shutdown();
}
