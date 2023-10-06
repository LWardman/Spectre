#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AEquipment;


struct FInventorySlot
{
	FInventorySlot(){}
	FInventorySlot(int32 ID) : SlotID(ID) {}

	FInventorySlot* NextSlot = nullptr;
	FInventorySlot* PrevSlot = nullptr;

	AEquipment* Equipment = nullptr;

	int32 SlotID = 0;

	void SetSlotLinks(FInventorySlot* _PrevSlot, FInventorySlot* _NextSlot)
	{
		PrevSlot = _PrevSlot;
		NextSlot = _NextSlot;
	}

	void LogSlotID() const
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory Slot %i"), SlotID);
	}
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPECTRE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:

	FInventorySlot CurrentSlot;

	FInventorySlot InventorySlot1{1};
	FInventorySlot InventorySlot2{2};
	FInventorySlot InventorySlot3{3};

	AEquipment* GetCurrentItem() const;

	void CycleInventoryForwards();

	void CycleInventoryBackwards();

	void InitialiseInventory();
};
