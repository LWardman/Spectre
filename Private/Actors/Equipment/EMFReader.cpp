
#include "Actors/Equipment/EMFReader.h"

#include "Components/PointLightComponent.h"


AEMFReader::AEMFReader()
{
	PrimaryActorTick.bCanEverTick = false;

	PowerIndicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("Power Indicator"));
	PowerIndicator->SetupAttachment(Mesh);

	Level_1_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 1"));
	Level_1_Indicator->SetupAttachment(Mesh);

	Level_2_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 2"));
	Level_2_Indicator->SetupAttachment(Mesh);

	Level_3_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 3"));
	Level_3_Indicator->SetupAttachment(Mesh);

	Level_4_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 4"));
	Level_4_Indicator->SetupAttachment(Mesh);

	Level_5_Indicator = CreateDefaultSubobject<UPointLightComponent>(TEXT("EMF 5"));
	Level_5_Indicator->SetupAttachment(Mesh);
}

void AEMFReader::TurnedOn()
{
	Super::TurnedOn();
}

void AEMFReader::TurnedOff()
{
	Super::TurnedOff();
}