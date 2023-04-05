// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveCollection.h"

void UObjectiveCollection::ActiveObjective()
{
	Super::ActiveObjective();
	if (bOrderRequired)
	{
		HandleOrderRequired();
	}
	else
	{
		for (UObjective* obj : Objectives)
		{
			obj->ActiveObjective();
		}
	}
}

bool UObjectiveCollection::GetIsComplete() const
{
	for (UObjective* obj : Objectives)
	{
		if (!obj->GetIsComplete())
		{
			return false;
		}
	}
	return true;
}

UObjective* UObjectiveCollection::FindNexIncompleteObjective()
{
	for (UObjective* obj : Objectives)
	{
		if (!obj->GetIsComplete())
		{
			return obj;
		}
	}

	UObjective* objnull = nullptr;
	return objnull;
}

void UObjectiveCollection::HandleOrderRequired()
{
	CurrentObj = FindNexIncompleteObjective();
	if (CurrentObj)
	{
		CurrentObj->ActiveObjective();

		CurrentObj->OnCompleted.AddDynamic(this, &UObjectiveCollection::CollectionOnCompleteEvent);
	}
}

void UObjectiveCollection::CollectionOnCompleteEvent(UObjective* obj)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Quest Completed"));
	obj->OnCompleted.RemoveDynamic(this, &UObjectiveCollection::CollectionOnCompleteEvent);
	HandleOrderRequired();
}

void UObjectiveCollection::AddObjective(UObjective* obj)
{
	if (obj)
	{
		Objectives.Add(obj);
	}
}
