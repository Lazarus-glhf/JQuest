// Fill out your copyright notice in the Description page of Project Settings.

#include "Objective.h"

FText UObjective::GetObjectiveName() const
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

void UObjective::SetObjectiveBaseProperty(FText Name, float Time, float Grade)
{
	ObjectiveName = Name;
	TimeCount = Time;
	ObjectiveGrade = Grade;
}
