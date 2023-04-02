// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestReach.h"

void AQuestReach::PopulateObjectives(UObjCollection* RootCollection)
{

}

UObjCollection* AQuestReach::ConstructRootObjectiveCollection()
{
	UObjCollection* UC = NewObject<UObjCollection>(this);
	return UC;
}
