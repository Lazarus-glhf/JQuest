// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestReach.h"
#include "JQuest/Objectives/ObjReachDestination.h"

UObjectiveCollection* AQuestReach::ConstructRootObjectiveCollection()
{
	UObjectiveCollection* UC = NewObject<UObjectiveCollection>(this);

	UC->bOrderRequired = true;
	UC->ObjectiveName = FText(FText::FromString("Long way from home"));

	return UC;
}

void AQuestReach::PopulateObjectives(UObjectiveCollection* RootCollection)
{
	UObjReachDestination* ObjReach = NewObject<UObjReachDestination>(this);
	if (MegatonTrigger)
	{
		ObjReach->DestinationBox = MegatonTrigger;
	}

	ObjReach->SetObjectiveName(FText::FromString("Reached Magaton"));

	RootObjectiveCollection->AddObjective(ObjReach);
}
