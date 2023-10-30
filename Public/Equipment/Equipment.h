#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "Equipment.generated.h"

UCLASS()
class SPECTRE_API AEquipment : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	AEquipment();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	virtual void UseEquipment();

	virtual void Interact_Implementation() override;
};
