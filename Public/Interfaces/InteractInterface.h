#pragma once
 
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"
 
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};
 
class SPECTRE_API IInteractInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact();
};
