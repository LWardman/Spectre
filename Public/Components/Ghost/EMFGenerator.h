
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EMFGenerator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECTRE_API UEMFGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEMFGenerator();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SpawnEMFEvent(int32 Level, float Radius, FVector Center);
};
