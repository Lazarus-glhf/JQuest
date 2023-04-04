// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Components/BillboardComponent.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillBorad"));

}

UObjectiveCollection* AQuest::GetRootObjCollection() const
{
	return RootObjectiveCollection;
}

void AQuest::PopulateObjectives(UObjectiveCollection* RootCollection)
{
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();

	RootObjectiveCollection = ConstructRootObjectiveCollection();
	PopulateObjectives(RootObjectiveCollection);

	// TODO Active Root Objectives
	RootObjectiveCollection->ActiveObjective();
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::ActiveObjective()
{
}

UObjectiveCollection* AQuest::ConstructRootObjectiveCollection()
{
	UObjectiveCollection* UC = nullptr;
	return UC;
}


