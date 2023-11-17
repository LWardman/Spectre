#pragma once

#include "CoreMinimal.h"
#include "Equipment.h"
#include "GameFramework/Actor.h"
#include "Interfaces/SwitchInterface.h"
#include "Switchable.generated.h"

class UPowerSwitch;

UCLASS()
class SPECTRE_API ASwitchable : public AEquipment, public ISwitchInterface
{
	GENERATED_BODY()

public:
	ASwitchable();

	UFUNCTION()
	void ToggleEquipment(bool BTurnedOn);
	
	virtual void TurnedOn();

	virtual void TurnedOff();

	UPROPERTY(EditAnywhere)
	UPowerSwitch* PowerSwitch;

	virtual void Switch_Implementation() override;
};
