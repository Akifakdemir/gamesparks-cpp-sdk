#include "GameSparksPrivatePCH.h"
#include "GameSparksComponent.h"
#include "GameSparksModule.h"

UGameSparksComponent::UGameSparksComponent(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
	PrimaryComponentTick.bCanEverTick = true;
	this->bTickInEditor = false;
	this->bAutoActivate = false;
	
	BillboardSubComponent = ObjectInitializer.CreateDefaultSubobject<UBillboardComponent>(this, TEXT("BillboardSubComponent"));
	BillboardSubComponent->Mobility = EComponentMobility::Movable;
	BillboardSubComponent->AttachTo(this);
	BillboardSubComponent->Sprite = ConstructorHelpers::FObjectFinderOptional<UTexture2D>(TEXT("/GameSparks/gs_icon")).Get();
}

void UGameSparksComponent::Activate(bool bReset /*= false*/)
{
	
}

void UGameSparksComponent::Deactivate()
{
	
}

void UGameSparksComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGameSparksComponent::BeginDestroy()
{
	Super::BeginDestroy();
}

void UGameSparksComponent::Connect(FString apikey, FString secret, bool previewServer)
{
	if (UGameSparksModule::GetModulePtr() != nullptr)
		UGameSparksModule::GetModulePtr()->Initialize(apikey, secret, previewServer);
}

void UGameSparksComponent::Disconnect()
{
	if (UGameSparksModule::GetModulePtr() != nullptr)
		UGameSparksModule::GetModulePtr()->Shutdown();
}

void UGameSparksComponent::SendRequest(UGSUERequest* request)
{

}

void UGameSparksComponent::SendAuthenticationRequest(FString username, FString password)
{
	
}
