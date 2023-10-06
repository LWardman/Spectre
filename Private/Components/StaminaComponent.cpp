#include "Components/StaminaComponent.h"

#include "Characters/PlayerCharacter.h"


UStaminaComponent::UStaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	CurrentStamina = MaxStamina; // Ensures all players with this component start at max stamina.

	Parent = Cast<APlayerCharacter>(GetOwner());
}

void UStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RestoreStamina(RegenRate * DeltaTime);
}

void UStaminaComponent::UseStamina(float StaminaAmount)
{
	CurrentStamina -= StaminaAmount;
	
	if (CurrentStamina < 0)
	{
		CurrentStamina = 0;
	}
}

void UStaminaComponent::RestoreStamina(float StaminaAmount)
{
	CurrentStamina += StaminaAmount;

	if (CurrentStamina > MaxStamina)
	{
		CurrentStamina = MaxStamina;
	}
}
