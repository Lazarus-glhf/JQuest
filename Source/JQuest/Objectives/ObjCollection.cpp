// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjCollection.h"

void UObjCollection::ActiveObjective()
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

bool UObjCollection::GetIsComplete() const
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

UObjective* UObjCollection::FindNexIncompleteObjective()
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

void UObjCollection::HandleOrderRequired()
{
	UObjective* obj = FindNexIncompleteObjective();
	if (obj)
	{
		obj->ActiveObjective();

		obj->OnCompleted.AddDynamic(this, &UObjCollection::CollectionOnCompleteEvent);
	}
}

void UObjCollection::CollectionOnCompleteEvent(UObjective* obj)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Quest Completed"));
	obj->OnCompleted.RemoveDynamic(this, &UObjCollection::CollectionOnCompleteEvent);
	HandleOrderRequired();
}

void UObjCollection::AddObjective(UObjective* obj)
{
	Objectives.Add(obj);
}
