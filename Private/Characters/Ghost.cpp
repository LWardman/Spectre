
#include "Characters/Ghost.h"

AGhost::AGhost()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGhost::BeginPlay()
{
	Super::BeginPlay();
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
