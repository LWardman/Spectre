#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Equipment.generated.h"

UCLASS()
class SPECTRE_API AEquipment : public AActor
{
	GENERATED_BODY()
	
public:	
	AEquipment();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	virtual void UseEquipment();
};
