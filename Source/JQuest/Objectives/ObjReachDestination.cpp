// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjReachDestination.h"

void UObjReachDestination::ActiveObjective()
{
	Super::ActiveObjective();

	// TODO Add Type Check

	Destination->OnActorBeginOverlap.AddDynamic(this, &UObjReachDestination::HandleOverlapEvent);
}

void UObjReachDestination::HandleOverlapEvent(AActor* OverlappedActor, AActor* OtherActor)
{
	Destination->OnActorBeginOverlap.RemoveDynamic(this, &UObjReachDestination::HandleOverlapEvent);

	bReachedDestination = true;

	OnCompleted.Broadcast(this);
}

bool UObjReachDestination::GetIsComplete() const
{
	return bReachedDestination;
}
