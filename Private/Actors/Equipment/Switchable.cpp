#include "Actors/Equipment/Switchable.h"

#include "Components/PowerSwitch.h"


ASwitchable::ASwitchable()
{
	PrimaryActorTick.bCanEverTick = true;

	PowerSwitch = CreateDefaultSubobject<UPowerSwitch>(TEXT("Power Switch"));

	if (PowerSwitch)
	{
		PowerSwitch->SwitchToggled.AddDynamic(this, &ASwitchable::ToggleEquipment);
	}
}

void ASwitchable::ToggleEquipment(bool bEquipmentTurnedOn)
{
	bEquipmentTurnedOn ? TurnedOn() : TurnedOff();
}

void ASwitchable::TurnedOn()
{
	UE_LOG(LogTemp, Display, TEXT("Turned On"));
}

void ASwitchable::TurnedOff()
{
	UE_LOG(LogTemp, Display, TEXT("Turned Off"));
}

void ASwitchable::Switch_Implementation()
{
	if (PowerSwitch)
	{
		PowerSwitch->ToggleSwitch();
	}
}
