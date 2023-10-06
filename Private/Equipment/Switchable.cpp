#include "Equipment/Switchable.h"

#include "Components/PowerSwitch.h"


ASwitchable::ASwitchable()
{
	PrimaryActorTick.bCanEverTick = true;

	PowerSwitch = CreateDefaultSubobject<UPowerSwitch>(TEXT("Power Switch"));
}

void ASwitchable::TurnedOn()
{
	
}

void ASwitchable::TurnedOff()
{
	
}
