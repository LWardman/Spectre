#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UInventoryComponent;
class UStaminaComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class AEquipment;

struct FInputActionValue;

UCLASS()
class SPECTRE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere)
	UStaminaComponent* Stamina;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_Look;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_Sprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_Crouch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_UseEquipment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_ToggleEquipment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_CycleInventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_DropItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_Interact;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_OpenJournal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* IA_OpenMenu;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void SprintPressed(const FInputActionValue& Value);

	void SprintHeld(const FInputActionValue& Value);

	void SprintReleased(const FInputActionValue& Value);

	void CrouchPressed(const FInputActionValue& Value);

	void UseEquipment(const FInputActionValue& Value);

	void ToggleEquipment(const FInputActionValue& Value);

	void CycleInventory(const FInputActionValue& Value);

	void DropItem(const FInputActionValue& Value);

	void Interact(const FInputActionValue& Value);

	void OpenJournal(const FInputActionValue& Value);

	void OpenMenu(const FInputActionValue& Value);

	FHitResult LineTraceForward(float TraceLength);

	float CrouchSpeed = 250.f;
	float WalkSpeed = 400.f;
	float SprintSpeed = 600.f;

	bool bSprinting = false;
	float SprintDrain = 25.f;

	void PassEquipmentToInventory(AEquipment* Equipment);

	void EquipItem(const AEquipment* Equipment);
};
