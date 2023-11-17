
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ghost.generated.h"

class UEMFGenerator;

UCLASS()
class SPECTRE_API AGhost : public ACharacter
{
	GENERATED_BODY()

public:
	AGhost();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UEMFGenerator* EMF_Generator;

	// These stats will be used on a scale of 0 - 10, 5 being default.
	
	int32 Aggressiveness = 5;	// Determines how much the ghost will attack or try to discourage the player.
	
	int32 Interactiveness = 5;	// Determines how often the ghost will initiate events with the environment and equipment.
	
	int32 Curiosity = 5;		// Determines how much the ghost will follow the player / change rooms.


	float Speed = 550.f;
	
	
	void IncreaseStat(int32& Stat, int32 Increment);

	void DecreaseStat(int32& Stat, int32 Decrement);

	void LogStats() const; // Debug function

};
