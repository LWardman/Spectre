#include "Components/InventoryComponent.h"

#include "Equipment/Equipment.h"


UInventoryComponent::UInventoryComponent()
{
	TSharedRef<FInventorySlot> Slot1Ref(new FInventorySlot(1));
	TSharedRef<FInventorySlot> Slot2Ref(new FInventorySlot(2));
	TSharedRef<FInventorySlot> Slot3Ref(new FInventorySlot(3));
    
	Slot1 = Slot1Ref;
	Slot2 = Slot2Ref;
	Slot3 = Slot3Ref;

	CurrentSlot = Slot1;

	InitialiseInventory();
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

AEquipment* UInventoryComponent::GetCurrentItem() const 
{
	if (CurrentSlot)
	{
		return CurrentSlot->Equipment;
	}
	return nullptr;
}

void UInventoryComponent::CycleInventoryForwards()
{
	if ( CurrentSlot && CurrentSlot->NextSlot)
	{
		CurrentSlot->LogSlotID();
		CurrentSlot = CurrentSlot->NextSlot;
		CurrentSlot->LogSlotID();
	}
}

void UInventoryComponent::CycleInventoryBackwards()
{
	if (CurrentSlot && CurrentSlot->PrevSlot)
	{
		CurrentSlot->LogSlotID();
		CurrentSlot = CurrentSlot->PrevSlot;
		CurrentSlot->LogSlotID();
	}
}

void UInventoryComponent::InitialiseInventory()
{
	Slot1->SetSlotLinks(Slot3, Slot2);

	Slot2->SetSlotLinks(Slot1, Slot3);

	Slot3->SetSlotLinks(Slot2, Slot1);
}

void UInventoryComponent::TryAddItemToInventory(bool bOutSuccess, AEquipment* ItemToAdd)
{
	bOutSuccess = false;
	
	if (!CurrentSlot || !CurrentSlot->NextSlot || !CurrentSlot->NextSlot->NextSlot) return;

	TArray<TSharedPtr<FInventorySlot>> Slots = {CurrentSlot, CurrentSlot->NextSlot, CurrentSlot->NextSlot->NextSlot};

	for (TSharedPtr<FInventorySlot> Slot : Slots)
	{
		if (Slot.IsValid() && Slot->IsEmpty())
		{
			Slot->Equipment = ItemToAdd;
			bOutSuccess = true;
			return;
		}
	}
}
