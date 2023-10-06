#include "Components/PowerSwitch.h"

#include "Equipment/Switchable.h"

UPowerSwitch::UPowerSwitch()
{
	PrimaryComponentTick.bCanEverTick = false;

	Parent = Cast<ASwitchable>(GetOwner());
}

bool UPowerSwitch::IsTurnedOn() const
{
	return bPoweredOn;
}

void UPowerSwitch::ToggleSwitch()
{
	bPoweredOn = !bPoweredOn;

	if (Parent)
	{
		this->IsTurnedOn() ? Parent->TurnedOn() : Parent->TurnedOff();
	}
}
