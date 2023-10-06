#include "Equipment/Flashlight.h"

#include "Components/SpotLightComponent.h"
#include "Components/PowerSwitch.h"

AFlashlight::AFlashlight()
{
 	PrimaryActorTick.bCanEverTick = false;

	LightSource = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light Source"));
    LightSource->SetupAttachment(Mesh);

    PowerSwitch = CreateDefaultSubobject<UPowerSwitch>(TEXT("Power Switch"));
}

void AFlashlight::TurnedOn()
{
    Super::TurnedOn();

	if (LightSource)
    {
        LightSource->SetVisibility(true);
    }
}

void AFlashlight::TurnedOff()
{
    Super::TurnedOff();

	if (LightSource)
    {
        LightSource->SetVisibility(false);
    }
}

void AFlashlight::ToggleFlash()
{
	if (PowerSwitch)
    {
        PowerSwitch->ToggleSwitch();
    }
}
