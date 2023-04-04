// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JQuest/Tools/ReachBox.h"
#include "Objective.h"
#include "ObjReachDestination.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API UObjReachDestination : public UObjective
{
	GENERATED_BODY()

public:
	// Ä¿µÄµØ TriggerBox
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AReachBox* DestinationBox;

	virtual void ActiveObjective() override;

	virtual bool GetIsComplete() const override;

	UFUNCTION()
	void ObjReachHandleOverlapEvent(AActor* OverlappedActor, AActor* OtherActor);

private:
	bool bReachedDestination = false;
};
