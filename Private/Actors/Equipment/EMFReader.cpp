
#include "Actors/Equipment/EMFReader.h"

#include "Components/PointLightComponent.h"
#include "Components/PowerSwitch.h"


AEMFReader::AEMFReader()
{
	PrimaryActorTick.bCanEverTick = false;

	PowerIndicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("Power Indicator"));
	PowerIndicator->SetupAttachment(Mesh);

	Level_1_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 1"));
	Level_1_Indicator->SetupAttachment(Mesh);
	EMFIndicators.Add(Level_1_Indicator);

	Level_2_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 2"));
	Level_2_Indicator->SetupAttachment(Mesh);
	EMFIndicators.Add(Level_2_Indicator);

	Level_3_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 3"));
	Level_3_Indicator->SetupAttachment(Mesh);
	EMFIndicators.Add(Level_3_Indicator);

	Level_4_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 4"));
	Level_4_Indicator->SetupAttachment(Mesh);
	EMFIndicators.Add(Level_4_Indicator);

	Level_5_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 5"));
	Level_5_Indicator->SetupAttachment(Mesh);
	EMFIndicators.Add(Level_5_Indicator);
}

void AEMFReader::TurnedOn()
{
	Super::TurnedOn();

	if (PowerIndicator)
	{
		PowerIndicator->SetVisibility(true);
	}
}

void AEMFReader::TurnedOff()
{
	Super::TurnedOff();

	if (PowerIndicator)
	{
		PowerIndicator->SetVisibility(false);
	}
}

void AEMFReader::RecieveEMFSignal(int32 EMF_Level)
{
	if (!PowerSwitch || !PowerSwitch->IsTurnedOn()) return;
	
	if (EMF_Level < 0 || EMF_Level > 5)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid EMF level"));
		return;
	}

	for (int32 Idx = 0; Idx < EMFIndicators.Num(); Idx++)
	{
		if (UPointLightComponent* Indicator = EMFIndicators[Idx])
		{
			Indicator->SetVisibility(Idx < EMF_Level);
		}
	}
}
