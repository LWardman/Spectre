#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class APlayerCharacter;
class AEquipment;

struct FInventorySlot
{
	FInventorySlot(){}
	FInventorySlot(int32 ID) : SlotID(ID) {}

	TSharedPtr<FInventorySlot> NextSlot;
	TSharedPtr<FInventorySlot> PrevSlot;

	AEquipment* Equipment = nullptr;

	int32 SlotID = 0;

	void SetSlotLinks(const TSharedPtr<FInventorySlot> &_PrevSlot, const TSharedPtr<FInventorySlot> &_NextSlot)
	{
		PrevSlot = _PrevSlot;
		NextSlot = _NextSlot;
	}

	void LogSlotID() const
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory Slot %i"), SlotID);
	}

	bool IsEmpty() const
	{
		return (Equipment == nullptr);
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
	UPROPERTY()
	APlayerCharacter* Parent;

	TSharedPtr<FInventorySlot> CurrentSlot;

	TSharedPtr<FInventorySlot> Slot1;
	TSharedPtr<FInventorySlot> Slot2;
	TSharedPtr<FInventorySlot> Slot3;

	AEquipment* GetCurrentItem() const;

	void CycleInventoryForwards();

	void CycleInventoryBackwards();

	void InitialiseInventory();

	bool TryAddItemToInventory(AEquipment* ItemToAdd);

	void DropCurrentItem();
};
