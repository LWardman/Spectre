
#include "Actors/EMFSphere.h"

#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"

AEMFSphere::AEMFSphere()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Capsule"));
}

void AEMFSphere::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		DestructHandle,
		this,
		&AEMFSphere::OnDestruct,
		Lifetime,
		false
		);
}

void AEMFSphere::Initialise(int32 EMF_Level, float EMF_Radius, FVector EMF_Center)
{
	EMF = EMF_Level;
	Radius = EMF_Radius;
	Center = EMF_Center;

	this->SetActorLocation(Center);

	if (CollisionCapsule)
	{
		CollisionCapsule->SetCapsuleSize(EMF_Radius, EMF_Radius, true);
	}

	DrawDebugSphere(GetWorld(), EMF_Center, EMF_Radius, 16, FColor::Red, false, Lifetime);
}

void AEMFSphere::OnDestruct()
{
	this->Destroy();
}