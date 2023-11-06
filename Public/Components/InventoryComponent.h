#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class APlayerCharacter;
class AEquipment;

using FSlotPtr = TSharedPtr<struct FInventorySlot>;

struct FInventorySlot
{
	FInventorySlot(){}
	FInventorySlot(int32 ID) : SlotID(ID) {}

	FSlotPtr NextSlot;
	FSlotPtr PrevSlot;

	AEquipment* Equipment = nullptr;

	int32 SlotID = 0;

	void SetSlotLinks(const FSlotPtr &_PrevSlot, const FSlotPtr &_NextSlot)
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

	FVector HidingPlace = FVector(0, 0, 0);

	FSlotPtr CurrentSlot;

	FSlotPtr Slot1;
	FSlotPtr Slot2;
	FSlotPtr Slot3;

	AEquipment* GetCurrentItem() const;

	void CycleInventoryForwards();

	void CycleInventoryBackwards();

	void InitialiseInventory();

	bool TryAddItemToInventory(AEquipment* ItemToAdd);

	void DropCurrentItem();

	void SendEquipmentToHide(AEquipment* Equipment);

	void HandleRemovingEquipmentFromHand();

	void HandleEquippingNextItem();
};
