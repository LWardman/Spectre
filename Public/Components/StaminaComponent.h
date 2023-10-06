#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaminaComponent.generated.h"

class APlayerCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECTRE_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStaminaComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UseStamina(float StaminaAmount);

	void RestoreStamina(float StaminaAmount);

	APlayerCharacter* Parent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Gameplay Variables")
	float MaxStamina = 100.f;

	UPROPERTY(EditAnywhere, Category = "Gameplay Variables")
	float CurrentStamina = 100.f;	

	UPROPERTY(EditAnywhere, Category = "Gameplay Variables")
	float RegenRate = 10.f;
};
