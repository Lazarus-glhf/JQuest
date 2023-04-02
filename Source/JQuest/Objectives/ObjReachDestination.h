// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATriggerBox* Destination;

	virtual void ActiveObjective() override;

	virtual bool GetIsComplete() const override;

private:
	bool bReachedDestination = false;

	virtual void HandleOverlapEvent(AActor* OverlappedActor, AActor* OtherActor);
};
