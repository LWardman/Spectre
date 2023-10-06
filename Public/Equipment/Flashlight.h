#pragma once

#include "CoreMinimal.h"
#include "Equipment/Equipment.h"
#include "Flashlight.generated.h"

class USpotLightComponent;
class UPowerSwitch;

UCLASS()
class SPECTRE_API AFlashlight : public AEquipment
{
	GENERATED_BODY()

public:
	AFlashlight();

public:

	UPROPERTY(EditAnywhere)
	USpotLightComponent* LightSource;

	UPROPERTY(EditAnywhere)
	UPowerSwitch* PowerSwitch;
	
	virtual void TurnedOn() override;

	virtual void TurnedOff() override;

	UFUNCTION()
	void ToggleFlash();

};
