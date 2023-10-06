#include "Equipment/Equipment.h"

AEquipment::AEquipment()
{
 	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AEquipment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEquipment::TurnedOn()
{
	
}

void AEquipment::TurnedOff()
{
	
}

void AEquipment::UseEquipment()
{

}
