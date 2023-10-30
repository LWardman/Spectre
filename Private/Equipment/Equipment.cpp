#include "Equipment/Equipment.h"

#include "Characters/PlayerCharacter.h"

AEquipment::AEquipment()
{
 	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AEquipment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEquipment::UseEquipment()
{

}

void AEquipment::Interact_Implementation(APlayerCharacter* InteractingCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted with %s"), *this->GetActorNameOrLabel());

	InteractingCharacter->PassEquipmentToInventory(this);
}
