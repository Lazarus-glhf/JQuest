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

private:
	virtual void PopulateObjectives(UObjCollection* RootCollection) override;
	virtual UObjCollection* ConstructRootObjectiveCollection() override;
	
};
