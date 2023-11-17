
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EMFSphere.generated.h"

class UCapsuleComponent;

UCLASS()
class SPECTRE_API AEMFSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	AEMFSphere();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	UCapsuleComponent* CollisionCapsule;

	int32 EMF = 0;

	float Radius = 0;

	FVector Center = FVector::ZeroVector;

	float Lifetime = 10.0f;

	void Initialise(int32 EMF_Level, float EMF_Radius, FVector EMF_Center);

	void OnDestruct();

	FTimerHandle DestructHandle;
};
