#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerSwitch.generated.h"

class AEquipment;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECTRE_API UPowerSwitch : public UActorComponent
{
	GENERATED_BODY()

public:

	UPowerSwitch();

	AEquipment* Parent;

	bool bPoweredOn = false;

	bool IsTurnedOn() const;

	void ToggleSwitch();
		
};
