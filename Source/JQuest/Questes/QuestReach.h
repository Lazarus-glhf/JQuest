// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "QuestReach.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API AQuestReach : public AQuest
{
	GENERATED_BODY()

public:
	// �����⣬�ж��Ƿ񵽴���Ŀ�ĵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AReachBox* MegatonTrigger;

private:
	virtual void PopulateObjectives(UObjectiveCollection* RootCollection) override;

	virtual UObjectiveCollection* ConstructRootObjectiveCollection() override;
};
