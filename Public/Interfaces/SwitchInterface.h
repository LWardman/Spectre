#pragma once
 
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SwitchInterface.generated.h"
 
UINTERFACE(MinimalAPI)
class USwitchInterface : public UInterface
{
	GENERATED_BODY()
};
 
class SPECTRE_API ISwitchInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Switch();
};