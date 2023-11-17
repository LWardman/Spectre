
#include "Characters/Ghost.h"

#include "Components/Ghost/EMFGenerator.h"

AGhost::AGhost()
{
	PrimaryActorTick.bCanEverTick = true;

	EMF_Generator = CreateDefaultSubobject<UEMFGenerator>(TEXT("EMF Generator"));
}

void AGhost::BeginPlay()
{
	Super::BeginPlay();

	if (EMF_Generator)
	{
		EMF_Generator->SpawnEMFEvent(5, 100.0f, this->GetActorLocation());
	}
}

void AGhost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGhost::IncreaseStat(int32& Stat, int32 Increment)
{
	Stat += Increment;
	
	if (Stat >= 10)
	{
		Stat = 10;
	}
}

void AGhost::DecreaseStat(int32& Stat, int32 Decrement)
{
	Stat -= Decrement;
	
	if (Stat <= 0)
	{
		Stat = 0;
	}
}

void AGhost::LogStats() const
{
	UE_LOG(LogTemp, Warning, TEXT("Aggressiveness : %i"), Aggressiveness);
	UE_LOG(LogTemp, Warning, TEXT("Interactiveness : %i"), Interactiveness);
	UE_LOG(LogTemp, Warning, TEXT("Curiosity : %i"), Curiosity);
}
