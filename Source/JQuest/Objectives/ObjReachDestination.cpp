// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjReachDestination.h"

void UObjReachDestination::ActiveObjective()
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Activing ReachObjective"));
	Super::ActiveObjective();

	// TODO Add Type Check
	DestinationBox->OnActorBeginOverlap.AddDynamic(this, &UObjReachDestination::ObjReachHandleOverlapEvent);
}

void UObjReachDestination::ObjReachHandleOverlapEvent(AActor* OverlappedActor, AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Blue, TEXT("Handling OverlapEvent"));
	DestinationBox->OnActorBeginOverlap.RemoveDynamic(this, &UObjReachDestination::ObjReachHandleOverlapEvent);

	bReachedDestination = true;

	OnCompleted.Broadcast(this);
}

bool UObjReachDestination::GetIsComplete() const
{
	return bReachedDestination;
}
