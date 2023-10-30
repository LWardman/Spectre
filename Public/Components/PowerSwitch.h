#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerSwitch.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSwitchToggled, bool, BTurnedOn);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECTRE_API UPowerSwitch : public UActorComponent
{
	GENERATED_BODY()

public:

	bool bPoweredOn = true;

	bool IsTurnedOn() const;

	void ToggleSwitch();

	UPROPERTY(BlueprintAssignable, Category = "Event Dispatchers")
	FSwitchToggled SwitchToggled;
};
