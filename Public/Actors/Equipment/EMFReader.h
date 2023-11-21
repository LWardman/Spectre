
#pragma once

#include "CoreMinimal.h"
#include "Actors/Equipment/Switchable.h"
#include "EMFReader.generated.h"

class UPointLightComponent;

UCLASS()
class SPECTRE_API AEMFReader : public ASwitchable
{
	GENERATED_BODY()

public:
	AEMFReader();

	UPROPERTY(EditAnywhere)
	UPointLightComponent* PowerIndicator;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Level_1_Indicator;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Level_2_Indicator;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Level_3_Indicator;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Level_4_Indicator;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* Level_5_Indicator;

	TArray<UPointLightComponent*> EMFIndicators;

	virtual void TurnedOn() override;

	virtual void TurnedOff() override;

	void RecieveEMFSignal(int32 EMF_Level);
	
};
