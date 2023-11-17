#include "Components/Inventory/InventoryComponent.h"

#include "Characters/PlayerCharacter.h"
#include "Actors/Equipment/Equipment.h"

using FSlotRef = TSharedRef<FInventorySlot>;

UInventoryComponent::UInventoryComponent()
{
	Parent = Cast<APlayerCharacter>(GetOwner());
	
	FSlotRef Slot1Ref(new FInventorySlot(1));
	FSlotRef Slot2Ref(new FInventorySlot(2));
	FSlotRef Slot3Ref(new FInventorySlot(3));
    
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
	if (CurrentSlot && CurrentSlot->NextSlot)
	{
		CurrentSlot = CurrentSlot->NextSlot;
	}
}

void UInventoryComponent::CycleInventoryBackwards()
{
	if (CurrentSlot && CurrentSlot->PrevSlot)
	{
		CurrentSlot = CurrentSlot->PrevSlot;
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

	TArray<FSlotPtr> Slots = {CurrentSlot, CurrentSlot->NextSlot, CurrentSlot->NextSlot->NextSlot};

	for (FSlotPtr Slot : Slots)
	{
		if (Slot.IsValid() && Slot->IsEmpty())
		{
			Slot->Equipment = ItemToAdd;
			return true;
		}
	}
	return false;
}

void UInventoryComponent::DropCurrentItem()
{
	if (AEquipment* Equipment = GetCurrentItem())
	{
		Equipment->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Equipment->SetSimulatePhysicsAndCollision(true);

		if (CurrentSlot)
		{
			CurrentSlot->Equipment = nullptr;
		}
	}
}

void UInventoryComponent::SendEquipmentToHide(AEquipment* Equipment)
{
	if (Equipment == nullptr) return;

	Equipment->SetActorLocation(HidingPlace);
}

void UInventoryComponent::HandleRemovingEquipmentFromHand()
{
	if (AEquipment* Equipment = GetCurrentItem())
	{
		Equipment->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Equipment->SetSimulatePhysicsAndCollision(true);
		SendEquipmentToHide(Equipment);
	}
}

void UInventoryComponent::HandleEquippingNextItem()
{
	if (!CurrentSlot || !Parent) return;
		
	if (AEquipment* Equipment = GetCurrentItem())
	{
		Parent->EquipItem(Equipment);
	}
}