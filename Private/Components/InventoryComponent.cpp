#include "Components/InventoryComponent.h"

#include "Equipment/Equipment.h"


UInventoryComponent::UInventoryComponent()
{
	
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	InitialiseInventory();
}

AEquipment* UInventoryComponent::GetCurrentItem() const 
{
	return CurrentSlot.Equipment;
}

void UInventoryComponent::CycleInventoryForwards()
{
	if (CurrentSlot.NextSlot != nullptr)
	{
		CurrentSlot = *CurrentSlot.NextSlot;
	}
}

void UInventoryComponent::CycleInventoryBackwards()
{
	if (CurrentSlot.PrevSlot != nullptr)
	{
		CurrentSlot = *CurrentSlot.PrevSlot;
	}
}

void UInventoryComponent::InitialiseInventory()
{
	InventorySlot1.SetSlotLinks(&InventorySlot3, &InventorySlot2);

	InventorySlot2.SetSlotLinks(&InventorySlot1, &InventorySlot3);

	InventorySlot3.SetSlotLinks(&InventorySlot2, &InventorySlot1);

	CurrentSlot = InventorySlot1;
}
