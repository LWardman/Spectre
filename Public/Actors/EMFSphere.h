
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EMFSphere.generated.h"

UCLASS()
class SPECTRE_API AEMFSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	AEMFSphere();

protected:
	virtual void BeginPlay() override;

public:	

	int32 EMF = 0;

	float Radius = 0;

	FVector Center = FVector::ZeroVector;

	void Initialise(int32 EMF_Level, float EMF_Radius, FVector EMF_Center);

	void SpawnEMF();

	FTimerHandle DestructHandle;

};
