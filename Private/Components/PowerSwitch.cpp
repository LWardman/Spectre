#include "Components/PowerSwitch.h"

bool UPowerSwitch::IsTurnedOn() const
{
	return bPoweredOn;
}

void UPowerSwitch::ToggleSwitch()
{
	bPoweredOn = !bPoweredOn;

	SwitchToggled.Broadcast(this->IsTurnedOn());
}
