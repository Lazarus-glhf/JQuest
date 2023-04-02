// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjCollection.h"

void UObjCollection::ActiveObjective()
{
	Super::ActiveObjective();
	if (bOrderRequired)
	{
		UObjective* obj = FindNexIncompleteObjective();
		if (obj)
		{
			obj->ActiveObjective();
		}
	}
	else
	{
		for (UObjective* obj : Objectives)
		{
			obj->ActiveObjective();
		}
	}
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
