#include "Actors/Equipment/Equipment.h"

#include "Characters/PlayerCharacter.h"

AEquipment::AEquipment()
{
 	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AEquipment::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEquipment::UseEquipment()
{

}

void AEquipment::Interact_Implementation(APlayerCharacter* InteractingCharacter)
{
	//UE_LOG(LogTemp, Warning, TEXT("Interacted with %s"), *this->GetActorNameOrLabel());

	InteractingCharacter->PassEquipmentToInventory(this);
}

void AEquipment::SetSimulatePhysicsAndCollision(bool bSimulatePhysics)
{
	if (Mesh)
	{
		Mesh->SetSimulatePhysics(bSimulatePhysics);

		if (bSimulatePhysics)
		{
			Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		}
		else
		{
			Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		}
		
	}
}
