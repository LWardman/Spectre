#include "Characters/PlayerCharacter.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

#include "Components/InventoryComponent.h"
#include "Components/StaminaComponent.h"
#include "Equipment/Equipment.h"
#include "Interfaces/SwitchInterface.h"

APlayerCharacter::APlayerCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));

	Stamina = CreateDefaultSubobject<UStaminaComponent>(TEXT("Stamina"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetMesh(), "CameraSocket");
	Camera->bUsePawnControlRotation = true;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		// Movement
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);

		// Sprinting
		EnhancedInputComponent->BindAction(IA_Sprint, ETriggerEvent::Started, this, &APlayerCharacter::SprintPressed);
		EnhancedInputComponent->BindAction(IA_Sprint, ETriggerEvent::Triggered, this, &APlayerCharacter::SprintHeld);
		EnhancedInputComponent->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &APlayerCharacter::SprintReleased);

		// Crouching
		EnhancedInputComponent->BindAction(IA_Crouch, ETriggerEvent::Completed, this, &APlayerCharacter::CrouchPressed);

		// Equipment
		EnhancedInputComponent->BindAction(IA_UseEquipment, ETriggerEvent::Completed, this, &APlayerCharacter::UseEquipment);
		EnhancedInputComponent->BindAction(IA_ToggleEquipment, ETriggerEvent::Completed, this, &APlayerCharacter::ToggleEquipment);

		// Inventory
		EnhancedInputComponent->BindAction(IA_CycleInventory, ETriggerEvent::Triggered, this, &APlayerCharacter::CycleInventory);
		EnhancedInputComponent->BindAction(IA_DropItem, ETriggerEvent::Triggered, this, &APlayerCharacter::DropItem);

		// Interact
		EnhancedInputComponent->BindAction(IA_Interact, ETriggerEvent::Started, this, &APlayerCharacter::Interact);

		// HUD
		EnhancedInputComponent->BindAction(IA_OpenJournal, ETriggerEvent::Triggered, this, &APlayerCharacter::OpenJournal);
		EnhancedInputComponent->BindAction(IA_OpenMenu, ETriggerEvent::Triggered, this, &APlayerCharacter::OpenMenu);
	}
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void APlayerCharacter::SprintPressed(const FInputActionValue& Value)
{
	if (this->bIsCrouched) return;
	
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

	bSprinting = true;
}

void APlayerCharacter::SprintHeld(const FInputActionValue& Value)
{
	if (this->bIsCrouched) return;
	if (Stamina == nullptr) return;
	if (!bSprinting) return;
	
	const float DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);

	Stamina->UseStamina(DeltaSeconds * SprintDrain);

	if (Stamina->CurrentStamina <= 0)
	{
		SprintReleased(Value);
	}
}

void APlayerCharacter::SprintReleased(const FInputActionValue& Value)
{
	if (this->bIsCrouched) return;
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	bSprinting = false;
}

void APlayerCharacter::CrouchPressed(const FInputActionValue& Value)
{
	if (this->bIsCrouched)
	{
		this->UnCrouch();
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
	else
	{
		this->Crouch();
		GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
	}
}

void APlayerCharacter::UseEquipment(const FInputActionValue& Value)
{
	if (Inventory && Inventory->GetCurrentItem())
	{
		Inventory->GetCurrentItem()->UseEquipment();
	}
}

void APlayerCharacter::ToggleEquipment(const FInputActionValue& Value)
{
	if (Inventory == nullptr) return;

	if (AEquipment* Equipment = Inventory->GetCurrentItem())
	{
		if (Equipment->Implements<USwitchInterface>())
		{
			ISwitchInterface::Execute_Switch(Equipment);
		}
	}
}

void APlayerCharacter::CycleInventory(const FInputActionValue& Value)
{
	if (Inventory == nullptr) return;

	const float Direction = Value.GetMagnitude();

	(Direction > 0) ? Inventory->CycleInventoryForwards() : Inventory->CycleInventoryBackwards();
}

void APlayerCharacter::DropItem(const FInputActionValue& Value)
{
	if (Inventory)
	{
		Inventory->DropCurrentItem();
	}
}

void APlayerCharacter::Interact(const FInputActionValue& Value)
{
	const FHitResult Hit = LineTraceForward(750.f);

	if (!Hit.bBlockingHit) return;

	if (Hit.GetActor() && Hit.GetActor()->Implements<UInteractInterface>())
	{
		IInteractInterface::Execute_Interact(Hit.GetActor(), this);
	}
}

void APlayerCharacter::OpenJournal(const FInputActionValue& Value)
{
	
}

void APlayerCharacter::OpenMenu(const FInputActionValue& Value)
{
	
}

FHitResult APlayerCharacter::LineTraceForward(float TraceLength)
{
	FHitResult Hit;
	
	if (!Camera) return Hit;
	
	FVector TraceStart = Camera->GetComponentLocation();
	FVector TraceEnd = TraceStart + Camera->GetForwardVector() * TraceLength;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECollisionChannel::ECC_WorldDynamic, QueryParams);

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 2.0f);

	return Hit;
}

void APlayerCharacter::PassEquipmentToInventory(AEquipment* Equipment)
{
	if (Inventory)
	{

		if (Inventory->TryAddItemToInventory(Equipment))
		{
			// Destroy item
		}
	}
}

void APlayerCharacter::EquipItem(const AEquipment* Equipment)
{
	if (Equipment == nullptr) return;
	
	UE_LOG(LogTemp, Warning, TEXT("Equipping %s"), *Equipment->GetActorNameOrLabel());
}