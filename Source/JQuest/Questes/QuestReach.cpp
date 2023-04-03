// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestReach.h"
#include "Components/BoxComponent.h"

#include "JQuest/Objectives/ObjReachDestination.h"

void AQuestReach::PopulateObjectives(UObjCollection* RootCollection)
{
	UObjReachDestination* ObjReach = NewObject<UObjReachDestination>(this);
	if (MegatonTrigger)
	{
		ObjReach->Destination = MegatonTrigger;
	}

	ObjReach->SetObjectiveName(FText::FromString("Reached Magaton"));

	RootObjectiveCollection->AddObjective(ObjReach);
}

UObjCollection* AQuestReach::ConstructRootObjectiveCollection()
{
	UObjCollection* UC = NewObject<UObjCollection>(this);

	UC->bOrderRequired = true;
	UC->ObjectiveName = FText(FText::FromString("Long way from home"));

	return UC;
}

