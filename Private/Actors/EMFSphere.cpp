
#include "Actors/EMFSphere.h"

AEMFSphere::AEMFSphere()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEMFSphere::BeginPlay()
{
	Super::BeginPlay();
}

void AEMFSphere::Initialise(int32 EMF_Level, float EMF_Radius, FVector EMF_Center)
{
	EMF = EMF_Level;
	Radius = EMF_Radius;
	Center = EMF_Center;
}

void AEMFSphere::SpawnEMF()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning EMF"));
}

