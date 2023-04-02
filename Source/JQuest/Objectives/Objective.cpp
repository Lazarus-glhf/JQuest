// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

FName UObjective::GetObjectiveName() const
{
	return ObjectiveName;
}

bool UObjective::GetIsComplete() const
{
	return true;
}

bool UObjective::GetIsActive() const
{
	return bIsActive;
}

void UObjective::ActiveObjective()
{
	bIsActive = true;
}

void UObjective::SetObjectiveName(FName name)
{
	ObjectiveName = name;
}

