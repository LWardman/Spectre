#include "Equipment/Flashlight.h"

#include "Components/SpotLightComponent.h"

AFlashlight::AFlashlight()
{
 	PrimaryActorTick.bCanEverTick = false;

	LightSource = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light Source"));
    LightSource->SetupAttachment(Mesh);
}

void AFlashlight::TurnedOn()
{
    Super::TurnedOn();

	if (LightSource) LightSource->SetVisibility(true);
}

void AFlashlight::TurnedOff()
{
    Super::TurnedOff();

	if (LightSource) LightSource->SetVisibility(false);
}
