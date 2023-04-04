// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "ReachQuest.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API AReachQuest : public AQuest
{
	GENERATED_BODY()

public:
	// 盒体检测，判断是否到达了目的地
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AReachBox* MegatonTrigger;

private:
	virtual void PopulateObjectives(UObjectiveCollection* RootCollection) override;

	virtual UObjectiveCollection* ConstructRootObjectiveCollection() override;
};