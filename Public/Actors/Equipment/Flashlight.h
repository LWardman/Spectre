#pragma once

#include "CoreMinimal.h"
#include "Switchable.h"
#include "Flashlight.generated.h"

class USpotLightComponent;
class UPowerSwitch;

UCLASS()
class SPECTRE_API AFlashlight : public ASwitchable
{
	GENERATED_BODY()

public:
	AFlashlight();

	UPROPERTY(EditAnywhere)
	USpotLightComponent* LightSource;
	
	virtual void TurnedOn() override;

	virtual void TurnedOff() override;
};
