
#include "Components/Ghost/EMFGenerator.h"

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

