
#include "Components/Ghost/EMFGenerator.h"

#include "Actors/EMFSphere.h"


UEMFGenerator::UEMFGenerator()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEMFGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void UEMFGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UEMFGenerator::SpawnEMFEvent(int32 Level, float Radius, FVector Center)
{
	AActor* EMF_Sphere = GetWorld()->SpawnActor(AEMFSphere::StaticClass());

	if (AEMFSphere* EMF = Cast<AEMFSphere>(EMF_Sphere))
	{
		EMF->Initialise(Level, Radius, Center);
	}
}
