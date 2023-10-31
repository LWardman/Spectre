#include "Components/InventoryComponent.h"

#include "Characters/PlayerCharacter.h"
#include "Equipment/Equipment.h"


UInventoryComponent::UInventoryComponent()
{
	Parent = Cast<APlayerCharacter>(GetOwner());
	
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
	if (Parent && CurrentSlot && CurrentSlot->NextSlot)
	{
		CurrentSlot = CurrentSlot->NextSlot;
		
		CurrentSlot->LogSlotID();
		if (!CurrentSlot->IsEmpty())
		{
			Parent->EquipItem(GetCurrentItem());
		}
	}
}

void UInventoryComponent::CycleInventoryBackwards()
{
	if (Parent && CurrentSlot && CurrentSlot->PrevSlot)
	{
		CurrentSlot = CurrentSlot->PrevSlot;
		
		CurrentSlot->LogSlotID();
		if (!CurrentSlot->IsEmpty())
		{
			Parent->EquipItem(GetCurrentItem());
		}
	}
}

void UInventoryComponent::InitialiseInventory()
{
	Slot1->SetSlotLinks(Slot3, Slot2);

	Slot2->SetSlotLinks(Slot1, Slot3);

	Slot3->SetSlotLinks(Slot2, Slot1);
}

bool UInventoryComponent::TryAddItemToInventory(AEquipment* ItemToAdd)
{
	if (!CurrentSlot || !CurrentSlot->NextSlot || !CurrentSlot->NextSlot->NextSlot) return false;

	TArray<TSharedPtr<FInventorySlot>> Slots = {CurrentSlot, CurrentSlot->NextSlot, CurrentSlot->NextSlot->NextSlot};

	for (TSharedPtr<FInventorySlot> Slot : Slots)
	{
		if (Slot.IsValid() && Slot->IsEmpty())
		{
			Slot->Equipment = ItemToAdd;

			if (CurrentSlot == Slot && Parent)
			{
				Parent->EquipItem(ItemToAdd);
			}
			
			return true;
		}
	}
	return false;
}

void UInventoryComponent::DropCurrentItem()
{
	if (GetCurrentItem() == nullptr) return;
}