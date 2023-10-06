#pragma once

#include "CoreMinimal.h"
#include "Equipment.h"
#include "GameFramework/Actor.h"
#include "Switchable.generated.h"

class UPowerSwitch;

UCLASS()
class SPECTRE_API ASwitchable : public AEquipment
{
	GENERATED_BODY()

public:
	ASwitchable();

	virtual void TurnedOn();

	virtual void TurnedOff();

	UPROPERTY(EditAnywhere)
	UPowerSwitch* PowerSwitch;
};
