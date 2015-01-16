#pragma once

#include "GameSparks/GSData.h"
#include "GSUEData.generated.h"


UCLASS()
class UGSUEData : public UObject
{
	GENERATED_BODY()

public:
	void SetGSData(const GameSparks::Core::GSData& data)
	{
		m_Data = data;
	}

	//UFUNCTION(BlueprintCallable, Category = "GameSparks|General")
	//static FString GetString(FString name, UGSUEData* dataObj)
	//{
	//	return dataObj->GetString(TCHAR_TO_ANSI(*name)).GetValue().c_str();
	//}

protected:
	GameSparks::Core::GSData m_Data;

};